#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "Entity.h"
#include "Cell.h"
#include <vector>

namespace Tetris {

    class Board : public Entity{

    private:

        static constexpr int VISIBLE_CELL_START_ROW = 4;
        static constexpr int VISIBLE_CELL_END_ROW = 23;
        static constexpr int HIDDEN_CELL_START_ROW = 0;
        static constexpr int HIDDEN_CELL_END_ROW = 3;

        static constexpr int VISIBLE_CELL_START_COLUMN = 0;
        static constexpr int VISIBLE_CELL_END_COLUMN = 9;

        static constexpr int ROW_COUNT = 24;
        static constexpr int COLUMN_COUNT = 10;

        std::vector<std::vector<std::unique_ptr<Cell>>> m_Cells;

    public:

        Board();
        void Update() override;
        void Draw() override;
        ~Board() override;

    };
}


#endif //BOARD_H
