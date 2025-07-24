#include "Board.h"
#include <iostream>

namespace Tetris {
    Board::Board() {
        m_Cells.resize(ROW_COUNT);
        for(int i = 0; i < ROW_COUNT; i++) {
            m_Cells[i].resize(COLUMN_COUNT);
            for(int j = 0; j < COLUMN_COUNT; j++) {
                int yPosition = GetRowPositionFromIndex(i);
                int xPosition = GetColumnPositionFromIndex(j);
                m_Cells[i][j] = std::make_unique<Cell>(xPosition, yPosition);
            }
        }
    }

    void Board::Update() {
        for(int i = VISIBLE_CELL_START_ROW; i < ROW_COUNT; i++) {
            for(int j = 0; j < COLUMN_COUNT; j++) {
                m_Cells[i][j]->Update();
            }
        }
    }

    void Board::Draw() {
        for(int i = VISIBLE_CELL_START_ROW; i < ROW_COUNT; i++) {
            for(int j = 0; j < COLUMN_COUNT; j++) {
                m_Cells[i][j]->Draw();
            }
        }
    }

    void Board::SetCellAsOccupied(const Vector2Int& position) {
        int rowIndex = GetRowIndexFromPosition(position.y);
        int colIndex = GetColumnIndexFromPosition(position.x);
        m_Cells[rowIndex][colIndex]->SetOccupied(GameConstants::ColorType::Green);
    }

    int Board::GetRowPositionFromIndex(const int rowIndex) {
        return GameConstants::GetPositionFromIndex(rowIndex) + GameConstants::TOP_PADDING;
    }

    int Board::GetColumnPositionFromIndex(const int colIndex) {
        return GameConstants::GetPositionFromIndex(colIndex) + GameConstants::LEFT_PADDING;
    }

    int Board::GetRowIndexFromPosition(const int rowPosition) {
        return GameConstants::GetIndexFromPosition(rowPosition - GameConstants::TOP_PADDING);
    }

    int Board::GetColumnIndexFromPosition(const int columnPosition) {
        return GameConstants::GetIndexFromPosition(columnPosition - GameConstants::LEFT_PADDING);
    }

    void Board::ClampPosition(Vector2Int& position) {
        int rowIndex = GetRowIndexFromPosition(position.y);
        int colIndex = GetColumnIndexFromPosition(position.x);
        if(rowIndex >= ROW_COUNT) {
            position.y = GetRowPositionFromIndex(ROW_COUNT - 1);
        }

        if(colIndex >= COLUMN_COUNT) {
            position.x = GetColumnPositionFromIndex(COLUMN_COUNT - 1);
        }
        else if(colIndex < 0) {
            position.x = GetColumnPositionFromIndex(0);
        }
    }

    bool Board::CheckIfValidRowIndex(const int rowIndex) {
        if(rowIndex >= ROW_COUNT) {
            return false;
        }
        return true;
    }

    bool Board::CheckIfValidColumnIndex(const int colIndex) {
        if(colIndex < 0 || colIndex >= COLUMN_COUNT) {
            return false;
        }
        return true;
    }

    bool Board::CheckIfOccupied(const Vector2Int& positionToCheck) const {
        int rowIndex = GetRowIndexFromPosition(positionToCheck.y);
        int colIndex = GetColumnIndexFromPosition(positionToCheck.x);
        return m_Cells[rowIndex][colIndex]->IsOccupied();
    }

    Board::~Board() {
        std::cout << "Board Destroyed\n";
    }
}