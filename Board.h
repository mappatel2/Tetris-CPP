#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "Entity.h"
#include "Cell.h"
#include <vector>

namespace Tetris {

    class Board : public Entity{

    public:

        static constexpr int ROW_COUNT = 24;
        static constexpr int COLUMN_COUNT = 10;
        static constexpr int VISIBLE_CELL_START_ROW = 4;
        static constexpr int VISIBLE_CELL_START_COLUMN = 0;

    private:

        bool m_Debug = true;
        std::vector<std::vector<std::unique_ptr<Cell>>> m_Cells;

    public:

        Board();
        void Update() override;
        void Draw() override;
        ~Board() override;

        bool CheckIfOccupied(const Vector2Int& position) const;
        void SetCellAsOccupied(const Vector2Int& position);

        static int GetRowPositionFromIndex(int rowIndex);
        static int GetColumnPositionFromIndex(int colIndex);
        static int GetRowIndexFromPosition(int rowPosition);
        static int GetColumnIndexFromPosition(int columnPosition);
        static void ClampPosition(Vector2Int& position);
        static bool CheckIfValidRowIndex(int rowIndex);
        static bool CheckIfValidColumnIndex(int colIndex);
    };
}


#endif //BOARD_H
