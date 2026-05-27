#include "Game.h"
#include <iostream>
#include "InputHandler.h"
#include "PreviewBlockUI.h"

namespace Tetris {
    Game::Game() {

        m_Board = std::make_unique<Board>();
        m_InputHandler = std::make_unique<InputHandler>();
        m_BlockSpawner = std::make_unique<BlockSpawner>();
        m_PreviewBlockUI = std::make_unique<PreviewBlockUI>();
        m_DebugPanel = std::make_unique<DebugPanelUI>();

        InitBlock();

        m_CanSpawn = false;
    }

    void Game::Run() {
        Update();
        Render();
    }

    void Game::Update() {
        if(m_CanSpawn) {
            if(m_SpawnTimer >= m_SpawnInterval) {
                m_SpawnTimer = 0.F;
                m_CanSpawn = false;
                InitBlock();
            }
            else {
                m_SpawnTimer += GetFrameTime();
            }

            return;
        }

        UpdateInput();
        UpdateGravity();
        UpdateBlock();
        UpdateBoard();
    }

    void Game::Render() {
        m_Board->Draw();
        if (!m_OccupyCellOnBoard) m_Block->Draw();
        m_PreviewBlockUI->Draw(m_BlockSpawner->GetPreviewBag());
        RenderDebugPanel();
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }

    void Game::InitBlock() {
        if(m_Block == nullptr) {
            m_Block = std::make_unique<Block>();
        }

        int xPosition = GridConfig::GetColumnPositionFromIndex(Config::START_COLUMN_INDEX);
        int yPosition = GridConfig::GetRowPositionFromIndex(Config::START_ROW_INDEX);
        auto blockType = m_BlockSpawner->GetTetrisBlock();
        m_Block->Init(blockType, xPosition, yPosition);

        m_HasLanded = false;
        m_OccupyCellOnBoard = false;
        m_HasLandedTimer = 0.F;
        m_LowestRowReached = -1;

        UpdateGhostPosition();
    }

    void Game::UpdateInput() {
        m_MovementVector.x = 0;
        m_MovementVector.y = 0;
        m_WantsToRotate = false;

        m_InputHandler->Update();

        if(m_InputHandler->CanExecuteLeft()) {
            m_MovementVector.x = -1;
        }
        else if(m_InputHandler->CanExecuteRight()) {
            m_MovementVector.x = 1;
        }

        if(m_InputHandler->CanExecuteDown()) {
            m_MovementVector.y = 1;
        }

        if(m_InputHandler->CanExecuteUp()) {
            m_WantsToRotate = true;
        }

        if (m_InputHandler->CanExecuteEnableDebugPanel()) {
            m_EnableDebugPanel = !m_EnableDebugPanel;
        }
    }

    void Game::UpdateGravity() {
        //When we press the down key, we reset Move Down Timer
        if (m_MovementVector.y != 0) {
            m_MoveDownTimer = m_MoveDownInterval;
        }

        if(m_MoveDownTimer <= 0.f) {
            m_MoveDownTimer = m_MoveDownInterval;
            m_MovementVector.y = 1;
        }
        else {
            m_MoveDownTimer -= GetFrameTime();
        }
    }

    void Game::UpdateBlock() {

        if (m_OccupyCellOnBoard) return;

        bool isValidRotation = false;
        bool isValidPosition = false;

        if (m_WantsToRotate) {
            for (int i = 0; i < 5; i++) {
                m_Block->UpdateNextRotationIndex(i);
                if (m_Board->IsValidPosition(m_Block->GetPossibleNextPositionArr())) {
                    m_Block->UpdateCurrentRotationIndex();
                    isValidRotation = true;
                    break;
                }
            }
        }

        if(m_MovementVector.x != 0 || m_MovementVector.y != 0) {
            m_Block->UpdateNextPosition(m_MovementVector);
            if (m_Board->IsValidPosition(m_Block->GetPossibleNextPositionArr())){
                m_Block->MoveBy(m_MovementVector);
                isValidPosition = true;
            }
        }

        if (isValidPosition || isValidRotation) {
            UpdateLowestRowReached();
            if (isValidPosition && m_MovementVector.x == 0) return;
            UpdateGhostPosition();
        }
        SetBlockHasLandedStatus();

        if(m_HasLanded) {
            if (isValidPosition || isValidRotation) {
                if (m_LockResets < m_LockResetLimit) {
                    m_LockResets++;
                    // std::cout << "Lock Resets Count : " << m_LockResets << std::endl;
                    m_HasLandedTimer = 0.F;
                }
            }

            if(m_HasLandedTimer < m_HasLandedInterval) {
                m_HasLandedTimer += GetFrameTime();
                // std::cout << "Has Landed Timer : " << m_HasLandedTimer << std::endl;
            }
            else {
                m_HasLandedTimer = 0.F;
                m_OccupyCellOnBoard = true;
                // std::cout << "Has Landed Timer Ended\n";
            }
        }
    }

    void Game::UpdateLowestRowReached() {
        int lowestRowIndex = INT_MIN;
        const std::array<Vector2Int, 4>& blockPositionArr = m_Block->GetPositionArr();
        for (int i = 0; i < 4; i++) {
            const Vector2Int blockPosition = blockPositionArr[i];
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPosition.y);
            lowestRowIndex = std::max(lowestRowIndex, rowIndex);
        }

        if (m_LowestRowReached < lowestRowIndex) {
            m_HasLandedTimer = 0.F;
            m_LockResets = 0;
            // std::cout << "Lowest Row Index : " << m_LowestRowReached << std::endl;
        }

        m_LowestRowReached = std::max(m_LowestRowReached, lowestRowIndex);
    }

    void Game::SetBlockHasLandedStatus() {

        //We First Check if The Next Row Is Valid Or Not
        const std::array<Vector2Int, 4>& blockPositionArr = m_Block->GetPositionArr();
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPositionArr[i].y);
            int nextRowIndex = rowIndex + 1;

            if(!Board::CheckIfValidRowIndex(nextRowIndex)) {
                //std::cout << "Has Landed Timer Started" << "\n";
                m_HasLanded = true;
                return;
            }
        }

        //We Check If Block On the Next Row Is Occupied Or Not
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPositionArr[i].y);
            int nextRowIndex = rowIndex + 1;
            int rowPosition = GridConfig::GetRowPositionFromIndex(nextRowIndex);
            int colPosition = blockPositionArr[i].x;
            Vector2Int nextPosition = {colPosition, rowPosition};
            if(m_Board->CheckIfOccupied(nextPosition)) {
                m_HasLanded = true;
                return;
            }
        }

        m_HasLanded = false;
    }

    void Game::UpdateGhostPosition() const {
        std::array<Vector2Int, 4> blockPositionArr = m_Block->GetPositionArr();
        bool isValidPosition = true;
        while (isValidPosition) {
            for (int i = 0; i < 4; i++) {
                blockPositionArr[i].y += Config::CELL_SIZE;
            }
            isValidPosition = m_Board->IsValidPosition(blockPositionArr);
        }
        for (int i = 0; i < 4; i++) {
            blockPositionArr[i].y -= Config::CELL_SIZE;
        }
        m_Block->UpdateGhostPosition(blockPositionArr);
    }

    void Game::UpdateBoard() {
        if(m_OccupyCellOnBoard) {
            const std::array<Vector2Int, 4>& blockPositionArr = m_Block->GetPositionArr();
            for(int i = 0; i < 4; i++) {
                m_Board->SetCellAsOccupied(blockPositionArr[i], m_Block->GetColor());
            }
            m_Board->ClearRows();
            m_CanSpawn = true;
        }

        m_Board->Update();
    }

    void Game::RenderDebugPanel() const {
        if (!m_EnableDebugPanel) return;

        m_DebugPanel->Draw({
            {"Block Type", ToString(m_Block->GetBlockType())},
            {"Rotation Index", ToString(m_Block->GetRotationStateIndex())},
            {"Lock Resets Count", ToString(m_LockResets)},
            {"Has Landed Timer", ToString(m_HasLandedTimer)},
            {"Lowest Row Reached", ToString(m_LowestRowReached)},
        });
    }
}