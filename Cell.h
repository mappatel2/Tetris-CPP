#ifndef CELL_H
#define CELL_H

#include "Entity.h"
#include "GameConstants.h"
#include "raylib.h"
#include "Vector2Int.h"

namespace Tetris {
    class Cell : public Entity{

    private:
        bool m_IsOccupied = false;
        bool m_IsVisible = false;

        GameConstants::ColorType m_OutlineColorType = GameConstants::ColorType::White;
        GameConstants::ColorType m_RectColorType = GameConstants::ColorType::Black;

        Vector2Int m_Position{};
        Color m_RectColor{};
        Color m_OutlineColor{};

    public:

        Cell() = default;
        Cell(int xPosition, int yPosition);

        void Update() override;
        void Draw() override;
        ~Cell() override = default;

    public:

        void SetOccupied(GameConstants::ColorType occupiedColorType);
        bool IsOccupied() const;
    };
}

#endif //CELL_H
