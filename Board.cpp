#include <array>
#include <iostream>

#include "Board.h"

namespace Tetris {
    Board::Board() {

        m_OutlineYPosition = GridConfig::GetRowPositionFromIndex(Config::VISIBLE_CELL_START_ROW-1);
        m_OutlineXPosition = GridConfig::GetColumnPositionFromIndex(-1);
        m_OutlineHeight = GridConfig::GetRowPositionFromIndex(Config::ROW_COUNT + 1) - m_OutlineYPosition;
        m_OutlineWidth = GridConfig::GetColumnPositionFromIndex(Config::COLUMN_COUNT + 1) - m_OutlineXPosition;

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
        DrawRectangleLines(m_OutlineXPosition, m_OutlineYPosition, m_OutlineWidth, m_OutlineHeight, RAYWHITE);
        for(int i = Config::VISIBLE_CELL_START_ROW; i < Config::ROW_COUNT; i++) {
            for(int j = 0; j < Config::COLUMN_COUNT; j++) {
                m_Cells[i][j]->Draw();
            }
        }
    }

    void Board::Reset() {
        for(int i = 0; i < m_Cells.size(); i++) {
            for(int j = 0; j < m_Cells[i].size(); j++) {
                m_Cells[i][j]->Reset();
            }
        }
    }

    void Board::SetCellAsOccupied(const Vector2Int& position, Color color) const {
        int rowIndex = GridConfig::GetRowIndexFromPosition(position.y);
        int colIndex = GridConfig::GetColumnIndexFromPosition(position.x);
        m_Cells[rowIndex][colIndex]->SetOccupiedStatus(true, color);
    }

    bool Board::IsValidPosition(const std::array<Vector2Int, 4>& nextPossiblePositions) const {
        for(int i = 0; i < 4; i++) {
            int rowIndex = GridConfig::GetRowIndexFromPosition(nextPossiblePositions[i].y);
            if(rowIndex >= Config::ROW_COUNT) {
                return false;
            }

            int colIndex = GridConfig::GetColumnIndexFromPosition(nextPossiblePositions[i].x);
            if(colIndex >= Config::COLUMN_COUNT) {
                return false;
            }
            if(colIndex < 0) {
                return false;
            }

            if(CheckIfOccupied(nextPossiblePositions[i])) {
                return false;
            }
        }
        return true;
    }

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

    void Board::ClearRows() const{

        int fullRowIndex = Config::ROW_COUNT - 1;
        int rowsCleared = 0;
        for(int i = Config::ROW_COUNT - 1; i >= Config::VISIBLE_CELL_START_ROW; i--) {
            bool isRowFull = CheckIfRowIsFull(i);
            if(!isRowFull) {
                for(int j = Config::VISIBLE_CELL_START_COLUMN; j < Config::COLUMN_COUNT; j++) {
                    const Color color = m_Cells[i][j]->GetRectColor();
                    m_Cells[fullRowIndex][j]->SetOccupiedStatus(m_Cells[i][j]->GetOccupiedStatus(), color);
                }
                fullRowIndex--;
            }
            else {
                rowsCleared++;
            }
        }
        for(int i = fullRowIndex; i >= Config::VISIBLE_CELL_START_ROW; i--) {
            for(int j = Config::VISIBLE_CELL_START_COLUMN; j < Config::COLUMN_COUNT; j++) {
                m_Cells[i][j]->SetOccupiedStatus(false, Graphics::GetCellColor(Graphics::ColorType::Black));
            }
        }

        EventMessage eventMessage {};

        switch (rowsCleared) {
            default:
            case 0: return;
            case 1:
                eventMessage.type = EventType::Lines_Cleared_1;
                break;
            case 2:
                eventMessage.type = EventType::Lines_Cleared_2;
                break;
            case 3:
                eventMessage.type = EventType::Lines_Cleared_3;
                break;
            case 4:
                eventMessage.type = EventType::Lines_Cleared_4;
                break;
        }

        Notify(eventMessage);
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