#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "Entity.h"
#include "Cell.h"
#include <vector>

namespace Tetris {

    class Board : public Entity{
    private:

        int m_OutlineYPosition;
        int m_OutlineXPosition;
        int m_OutlineHeight;
        int m_OutlineWidth;

        bool m_Debug = true;

        std::vector<std::vector<std::unique_ptr<Cell>>> m_Cells;

    public:

        Board();
        void Update() override;
        void Draw() override;
        ~Board() override;

        [[nodiscard]] bool CheckIfOccupied(const Vector2Int& position) const;
        [[nodiscard]] bool IsValidPosition(const std::array<Vector2Int, 4>& nextPossiblePositions) const;
        void SetCellAsOccupied(const Vector2Int& position, Color color) const;
        void ClearRows() const;

        static bool CheckIfValidRowIndex(int rowIndex);
        static bool CheckIfValidColumnIndex(int colIndex);

    private:
        [[nodiscard]] bool CheckIfRowIsFull(int rowIndex) const;
    };
}


#endif //BOARD_H
