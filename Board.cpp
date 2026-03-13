#include "Board.h"
#include <iostream>

namespace Tetris {
    Board::Board() {
        m_Cells.resize(Config::ROW_COUNT);
        for(int i = 0; i < Config::ROW_COUNT; i++) {
            m_Cells[i].resize(Config::COLUMN_COUNT);
            for(int j = 0; j < Config::COLUMN_COUNT; j++) {
                int yPosition = GridConfig::GetRowPositionFromIndex(i);
                int xPosition = GridConfig::GetColumnPositionFromIndex(j);
                m_Cells[i][j] = std::make_unique<Cell>(xPosition, yPosition);
            }
        }
    }

    void Board::Update() {
        for(int i = Config::VISIBLE_CELL_START_ROW; i < Config::ROW_COUNT; i++) {
            for(int j = 0; j < Config::COLUMN_COUNT; j++) {
                m_Cells[i][j]->Update();
            }
        }
    }

    void Board::Draw() {
        for(int i = Config::VISIBLE_CELL_START_ROW; i < Config::ROW_COUNT; i++) {
            for(int j = 0; j < Config::COLUMN_COUNT; j++) {
                m_Cells[i][j]->Draw();
            }
        }
    }

    void Board::SetCellAsOccupied(const Vector2Int& position, Color color) const {
        int rowIndex = GridConfig::GetRowIndexFromPosition(position.y);
        int colIndex = GridConfig::GetColumnIndexFromPosition(position.x);
        m_Cells[rowIndex][colIndex]->SetOccupiedStatus(true, color);
    }

    int Board::RowClampOffset(const Vector2Int& position) {
        int rowIndex = GridConfig::GetRowIndexFromPosition(position.y);
        if(rowIndex >= Config::ROW_COUNT) {
            return -1;
        }
        return 0;
    }

    int Board::ColumnClampOffset(const Vector2Int& position) {
        int colIndex = GridConfig::GetColumnIndexFromPosition(position.x);
        if(colIndex >= Config::COLUMN_COUNT) {
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
        if(rowIndex >= Config::ROW_COUNT) {
            return false;
        }
        return true;
    }

    bool Board::CheckIfValidColumnIndex(const int colIndex) {
        if(colIndex < 0 || colIndex >= Config::COLUMN_COUNT) {
            return false;
        }
        return true;
    }

    bool Board::CheckIfOccupied(const Vector2Int& positionToCheck) const {
        int rowIndex = GridConfig::GetRowIndexFromPosition(positionToCheck.y);
        int colIndex = GridConfig::GetColumnIndexFromPosition(positionToCheck.x);
        return m_Cells[rowIndex][colIndex]->GetOccupiedStatus();
    }

    void Board::ClearRows() const {
        int fullRowIndex = Config::ROW_COUNT - 1;
        for(int i = Config::ROW_COUNT - 1; i >= Config::VISIBLE_CELL_START_ROW; i--) {
            bool isRowFull = CheckIfRowIsFull(i);
            if(!isRowFull) {
                for(int j = Config::VISIBLE_CELL_START_COLUMN; j < Config::COLUMN_COUNT; j++) {
                    const Color color = m_Cells[i][j]->GetRectColor();
                    m_Cells[fullRowIndex][j]->SetOccupiedStatus(m_Cells[i][j]->GetOccupiedStatus(), color);
                }
                fullRowIndex--;
            }
        }
        for(int i = fullRowIndex; i >= Config::VISIBLE_CELL_START_ROW; i--) {
            for(int j = Config::VISIBLE_CELL_START_COLUMN; j < Config::COLUMN_COUNT; j++) {
                m_Cells[i][j]->SetOccupiedStatus(false, Graphics::GetCellColor(Graphics::ColorType::Black));
            }
        }
    }

    bool Board::CheckIfRowIsFull(const int rowIndex) const {
        if(!CheckIfValidRowIndex(rowIndex)) {
            std::cerr << "Row Index Out of Bounds\n";
            return true;
        }
        for(int j = Config::VISIBLE_CELL_START_COLUMN; j < Config::COLUMN_COUNT; j++) {
            if(!m_Cells[rowIndex][j]->GetOccupiedStatus()) return false;
        }
        return true;
    }

    Board::~Board() {
        std::cout << "Board Destroyed\n";
    }
}