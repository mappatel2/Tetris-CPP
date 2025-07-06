#ifndef CELL_H
#define CELL_H

#include "Entity.h"
#include "GameConstants.h"
#include "raylib.h"

namespace Tetris {
    class Cell : public Entity{

    private:
        bool m_IsOccupied = false;
        bool m_IsVisible = false;

        GameConstants::ColorType m_OutlineColorType = GameConstants::ColorType::White;
        GameConstants::ColorType m_RectColorType = GameConstants::ColorType::Black;

        Rectangle m_Rect;
        int m_XPosition;
        int m_YPosition;

        Color m_RectColor;
        Color m_OutlineColor;

    public:
        Cell() = default;
        Cell(bool isVisible, int xPosition, int yPosition);

        void Update() override;
        void Draw() override;
        ~Cell() override;

    public:

        void SetOccupied(GameConstants::ColorType occupiedColorType);
    };
}

#endif //CELL_H
