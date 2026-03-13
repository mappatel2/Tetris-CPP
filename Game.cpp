#include "Game.h"
#include <iostream>
#include "InputHandler.h"
#include "PreviewBlockUI.h"

namespace Tetris {
    Game::Game() {

        m_Board = std::make_unique<Board>();
        m_InputHandler = std::make_unique<InputHandler>();

        ShuffleTetrisBlockBag();
        InitPreviewBag();
        InitBlock();

        m_OutlineYPosition = GridConfig::GetRowPositionFromIndex(Config::VISIBLE_CELL_START_ROW-1);
        m_OutlineXPosition = GridConfig::GetColumnPositionFromIndex(-1);
        m_OutlineHeight = GridConfig::GetRowPositionFromIndex(Config::ROW_COUNT + 1) - m_OutlineYPosition;
        m_OutlineWidth = GridConfig::GetColumnPositionFromIndex(Config::COLUMN_COUNT + 1) - m_OutlineXPosition;

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
        UpdateBlock();
        UpdateBoard();
    }

    void Game::Render() {
        DrawRectangleLines(m_OutlineXPosition, m_OutlineYPosition, m_OutlineWidth, m_OutlineHeight, RAYWHITE);
        m_Board->Draw();
        m_Block->Draw();
        PreviewBlockUI::Draw();
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }

    void Game::UpdateInput() {
        m_InputVector.x = 0;
        m_InputVector.y = 0;

        m_InputHandler->Update();
        if(m_InputHandler->CanMoveLeft()) {
            m_InputVector.x = -1;
        }
        else if(m_InputHandler->CanMoveRight()) {
            m_InputVector.x = 1;
        }

        if(m_InputHandler->CanMoveDown()) {
            m_InputVector.y = 1;
        }
    }

    void Game::UpdateBlock() {
        m_Block->Update();
        if(m_InputVector.x != 0 || m_InputVector.y != 0) {
            m_Block->UpdateNextPosition(m_InputVector);
        }

        if(m_Block->HasMoved()) {
            UpdateBlockPosition();
            SetBlockHasLandedStatus();
        }
    }

    void Game::UpdateBoard() {
        if(m_Block->HasOccupiedCellOnBoard()) {
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
        auto blockType = GetTetrisBlock();
        m_Block->Init(blockType, xPosition, yPosition);
    }

    void Game::UpdateBlockPosition() {
        std::array<Vector2Int, 4>& possibleNextPositionArr = m_Block->GetPossibleNextPositionArr();
        m_RowClampOffset = 0;
        m_ColumnClampOffset = 0;
        for(int i = 0; i < 4; i++) {
            int tempOffset = Board::RowClampOffset(possibleNextPositionArr[i]);
            if(tempOffset != 0) {
                m_RowClampOffset = tempOffset;
            }
            tempOffset = Board::ColumnClampOffset(possibleNextPositionArr[i]);
            if(tempOffset != 0) {
                m_ColumnClampOffset = tempOffset;
            }
        }
        for(int i = 0; i < 4; i++) {
            possibleNextPositionArr[i].y += m_RowClampOffset * Config::CELL_SIZE;
            possibleNextPositionArr[i].x += m_ColumnClampOffset * Config::CELL_SIZE;
        }

        bool isNextPositionOccupied = false;
        for(int i = 0; i < 4; i++) {
            if(m_Board->CheckIfOccupied(possibleNextPositionArr[i])) {
                isNextPositionOccupied = true;
                break;
            }
        }
        if(!isNextPositionOccupied) {
            m_Block->UpdatePosition();
        }
    }

    void Game::SetBlockHasLandedStatus() {

        //We First Check if The Next Row Is Valid Or Not
        const std::array<Vector2Int, 4>& blockPositionArr = m_Block->GetPositionArr();
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPositionArr[i].y);
            int nextRowIndex = rowIndex + 1;

            if(!Board::CheckIfValidRowIndex(nextRowIndex)) {
                m_Block->SetHasLanded(true);
                return;
            }
        }

        //We Check If Block On the Next Row Is Occupied Or Not
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(blockPositionArr[i].y);
            int nextRowIndex = rowIndex + 1;
            int rowPosition = GridConfig::GetRowPositionFromIndex(nextRowIndex);
            int colPosition = blockPositionArr[i].x;
            m_TempPosition.Update(colPosition, rowPosition);
            if(m_Board->CheckIfOccupied(m_TempPosition)) {
                m_Block->SetHasLanded(true);
                return;
            }
        }

        m_Block->SetHasLanded(false);
    }

    void Game::InitPreviewBag() {
        for(int i = 0; i < 4; i++) {
            m_PreviewBag[i] = GetBlockFromShuffledBag();
        }
    }

    int Game::GetBlockFromShuffledBag() {
        if(m_CurrentShuffledBlockIndex >= m_Bag.size()) {
            ShuffleTetrisBlockBag();
        }
        return m_Bag[m_CurrentShuffledBlockIndex++];
    }

    int Game::GetBlockFromPreviewBag() {
        int blockIndex = m_PreviewBag[0];
        int nextBlockInShuffledBag = GetBlockFromShuffledBag();
        for(int i = 0; i < 3; i++) {
            m_PreviewBag[i] = m_PreviewBag[i+1];
        }
        m_PreviewBag[3] = nextBlockInShuffledBag;
        return blockIndex;
    }

    void Game::ShuffleTetrisBlockBag() {
        m_CurrentShuffledBlockIndex = 0;
        for(int i = m_Bag.size() - 1; i >= 0; i--) {
            int randomIndex = GetRandomValue(0, i);
            std::swap(m_Bag[i], m_Bag[randomIndex]);
        }
    }

    TetrominoType Game::GetTetrisBlock() {
        int blockInPreviewBag = GetBlockFromPreviewBag();
        return static_cast<TetrominoType>(blockInPreviewBag);
    }
}
