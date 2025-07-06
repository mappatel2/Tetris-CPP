#include "Board.h"
#include <iostream>

namespace Tetris {
    Board::Board() {
        m_Cells.resize(ROW_COUNT);
        for(int i = 0; i < ROW_COUNT; i++) {
            m_Cells[i].resize(COLUMN_COUNT);
            bool isVisible = i > HIDDEN_CELL_END_ROW;
            for(int j = 0; j < COLUMN_COUNT; j++) {
                int yPosition = (i - VISIBLE_CELL_START_ROW) * GameConstants::CELL_SIZE + GameConstants::TOP_PADDING;
                int xPosition = j * GameConstants::CELL_SIZE + GameConstants::LEFT_PADDING;
                m_Cells[i][j] = std::make_unique<Cell>(isVisible, xPosition, yPosition);
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

    Board::~Board() {
        std::cout << "Board Destroyed\n";
    }
}