#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "Entity.h"
#include "Cell.h"
#include <vector>

namespace Tetris {

    class Board : public Entity{
    private:

        bool m_Debug = true;
        std::vector<std::vector<std::unique_ptr<Cell>>> m_Cells;

    public:

        Board();
        void Update() override;
        void Draw() override;
        ~Board() override;

        bool CheckIfOccupied(const Vector2Int& position) const;
        void SetCellAsOccupied(const Vector2Int& position, Color color) const;
        void ClearRows() const ;

        static int RowClampOffset(const Vector2Int& position);
        static int ColumnClampOffset(const Vector2Int& position);
        static bool CheckIfValidRowIndex(int rowIndex);
        static bool CheckIfValidColumnIndex(int colIndex);

    private:
        bool CheckIfRowIsFull(int rowIndex) const;
    };
}


#endif //BOARD_H
