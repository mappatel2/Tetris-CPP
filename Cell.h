#ifndef CELL_H
#define CELL_H

#include "Entity.h"
#include "TetrisCore.h"
#include "raylib.h"
#include "Vector2Int.h"

namespace Tetris {
    class Cell : public Entity{

    private:
        bool m_IsOccupied = false;
        bool m_IsVisible = false;

        Vector2Int m_Position{};
        Color m_RectColor{};
        Color m_OutlineColor{};

    public:

        Cell() = default;
        Cell(int xPosition, int yPosition);

        void Update() override;
        void Draw() override;
        ~Cell() override = default;

        void Reset();
        void SetOccupiedStatus(bool status, Color occupiedColor);
        [[nodiscard]] bool GetOccupiedStatus() const;
        [[nodiscard]] Color GetRectColor() const;
    };
}

#endif //CELL_H
