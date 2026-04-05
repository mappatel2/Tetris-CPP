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
        m_Block->Draw();
        m_PreviewBlockUI->Draw(m_BlockSpawner->GetPreviewBag());
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }

    void Game::UpdateInput() {
        m_MovementVector.x = 0;
        m_MovementVector.y = 0;

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
            std::cout << "Executed Up Action" << std::endl;
        }
    }

    void Game::UpdateGravity() {
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

        if (m_OccupyCellOnBoard)
            return;

        if(m_HasLanded) {
            if(m_HasLandedTimer < m_HasLandedInterval) {
                m_HasLandedTimer += GetFrameTime();
            }
            else {
                m_HasLandedTimer = 0.F;
                m_OccupyCellOnBoard = true;
                std::cout << "Has Landed Timer Ended\n";
            }
        }

        if(m_MovementVector.x == 0 && m_MovementVector.y == 0) {
            return;
        }

        m_Block->UpdateNextPosition(m_MovementVector);
        if (m_Board->IsValidPosition(m_Block->GetPossibleNextPositionArr())){
            m_Block->MoveBy(m_MovementVector);
        }
        SetBlockHasLandedStatus();
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
    }

    void Game::SetBlockHasLandedStatus() {

        //We First Check if The Next Row Is Valid Or Not
        const std::array<Vector2Int, 4>& blockPositionArr = m_Block->GetPositionArr();
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPositionArr[i].y);
            int nextRowIndex = rowIndex + 1;

            if(!Board::CheckIfValidRowIndex(nextRowIndex)) {
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
}
