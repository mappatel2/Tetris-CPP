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

    void Board::SetCellAsOccupied(const Vector2Int& position, Graphics::ColorType colorType) const {
        int rowIndex = GetRowIndexFromPosition(position.y);
        int colIndex = GetColumnIndexFromPosition(position.x);
        m_Cells[rowIndex][colIndex]->SetOccupiedStatus(true, colorType);
    }



    int Board::RowClampOffset(const Vector2Int& position) {
        int rowIndex = GetRowIndexFromPosition(position.y);
        if(rowIndex >= ROW_COUNT) {
            return -1;
        }
        return 0;
    }

    int Board::ColumnClampOffset(const Vector2Int& position) {
        int colIndex = GetColumnIndexFromPosition(position.x);
        if(colIndex >= COLUMN_COUNT) {
            return -1;
        }
        if(colIndex < 0) {
            return 1;
        }
        return 0;
    }

    // int Board::ClampOffset(Vector2Int& position) {
    //     int rowIndex = GetRowIndexFromPosition(position.y);
    //     int colIndex = GetColumnIndexFromPosition(position.x);
    //     if(rowIndex >= ROW_COUNT) {
    //         position.y = GetRowPositionFromIndex(ROW_COUNT - 1);
    //     }
    //
    //     if(colIndex >= COLUMN_COUNT) {
    //         position.x = GetColumnPositionFromIndex(COLUMN_COUNT - 1);
    //     }
    //     else if(colIndex < 0) {
    //         position.x = GetColumnPositionFromIndex(0);
    //     }
    // }

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
        return m_Cells[rowIndex][colIndex]->GetOccupiedStatus();
    }

    void Board::ClearRows() const {
        int fullRowIndex = ROW_COUNT - 1;
        for(int i = ROW_COUNT - 1; i >= VISIBLE_CELL_START_ROW; i--) {
            bool isRowFull = CheckIfRowIsFull(i);
            if(!isRowFull) {
                for(int j = VISIBLE_CELL_START_COLUMN; j < COLUMN_COUNT; j++) {
                    const Graphics::ColorType colorType = m_Cells[i][j]->GetRectColorType();
                    m_Cells[fullRowIndex][j]->SetOccupiedStatus(m_Cells[i][j]->GetOccupiedStatus(), colorType);
                }
                fullRowIndex--;
            }
        }
        for(int i = fullRowIndex; i >= VISIBLE_CELL_START_ROW; i--) {
            for(int j = VISIBLE_CELL_START_COLUMN; j < COLUMN_COUNT; j++) {
                m_Cells[i][j]->SetOccupiedStatus(false, Graphics::ColorType::Black);
            }
        }
    }

    bool Board::CheckIfRowIsFull(const int rowIndex) const {
        if(!CheckIfValidRowIndex(rowIndex)) {
            std::cerr << "Row Index Out of Bounds\n";
            return true;
        }
        for(int j = VISIBLE_CELL_START_COLUMN; j < COLUMN_COUNT; j++) {
            if(!m_Cells[rowIndex][j]->GetOccupiedStatus()) return false;
        }
        return true;
    }

    Board::~Board() {
        std::cout << "Board Destroyed\n";
    }
}