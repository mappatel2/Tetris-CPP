#include "Game.h"
#include <iostream>
#include "InputHandler.h"

namespace Tetris {
    Game::Game() {
        m_Board = std::make_unique<Board>();
        m_InputHandler = std::make_unique<InputHandler>();

        int xPosition = Board::GetColumnPositionFromIndex(1);
        int yPosition = Board::GetRowPositionFromIndex(2);
        const Color redColor = GetCellColor(GameConstants::ColorType::Red);
        m_Block = std::make_unique<Block>(xPosition, yPosition, redColor);

        m_OutlineYPosition = Board::GetRowPositionFromIndex(Board::VISIBLE_CELL_START_ROW-1);
        m_OutlineXPosition = Board::GetColumnPositionFromIndex(-1);
        m_OutlineHeight = Board::GetRowPositionFromIndex(Board::ROW_COUNT + 1) - m_OutlineYPosition;
        m_OutlineWidth = Board::GetColumnPositionFromIndex(Board::COLUMN_COUNT + 1) - m_OutlineXPosition;
    }

    void Game::Run() {
        Update();
        Render();
    }

    void Game::Update() {

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

        m_Block->Update();
        if(m_InputVector.x != 0 || m_InputVector.y != 0) {
            m_Block->UpdateNextPosition(m_InputVector);
        }

        if(m_Block->HasMoved()) {
            UpdateBlockPosition();
            SetBlockHasLandedStatus();
        }

        if(m_Block->HasOccupiedCellOnBoard()) {
            m_Board->SetCellAsOccupied(m_Block->GetPosition());
            // std::cout << "Cell Occupied on Board\n";
        }

        m_Board->Update();
    }

    void Game::Render() {
        DrawRectangleLines(m_OutlineXPosition, m_OutlineYPosition, m_OutlineWidth, m_OutlineHeight, RAYWHITE);
        m_Board->Draw();
        m_Block->Draw();
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }

    void Game::UpdateBlockPosition() const {
        Vector2Int& possibleNextPosition = m_Block->GetPossibleNextPosition();
        Board::ClampPosition(possibleNextPosition);
        if(!m_Board->CheckIfOccupied(possibleNextPosition)) {
            m_Block->UpdatePosition();
        }
    }

    void Game::SetBlockHasLandedStatus() {
        const Vector2Int& blockPosition = m_Block->GetPosition();
        int rowIndex = Board::GetRowIndexFromPosition(blockPosition.y);
        int nextRowIndex = rowIndex + 1;

        //Check If Next Row is Out of Bounds
        if(!Board::CheckIfValidRowIndex(nextRowIndex)) {
            m_Block->SetHasLanded(true);
            return;
        }

        int rowPosition = Board::GetRowPositionFromIndex(nextRowIndex);
        int colPosition = blockPosition.x;
        m_TempPosition.Update(colPosition, rowPosition);
        bool isOccupied = m_Board->CheckIfOccupied(m_TempPosition);
        m_Block->SetHasLanded(isOccupied);
    }
}
