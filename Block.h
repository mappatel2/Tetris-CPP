#ifndef BLOCK_H
#define BLOCK_H

#include <memory>

#include "Entity.h"
#include "Vector2Int.h"
#include "raylib.h"
#include "GameConstants.h"
#include <iostream>

namespace Tetris {
    class Block : public Entity {

    private:

        float m_MoveDownTimer = 0.f;
        float m_HasLandedTimer = 0.f;
        const float m_HasLandedInterval = 2.F;
        const float m_MoveDownInterval = 0.8f;

        Vector2Int m_Position {};
        Vector2Int m_PossibleNextPosition {};
        Color m_Color {};

        bool m_HasMovedX = false;
        bool m_HasMovedY = false;
        bool m_HasLanded = false;
        bool m_OccupyCellOnBoard = false;
        bool m_IsVisible = false;

        int m_RowIndex = 0;
        int m_ColumnIndex = 0;

    public:

        Block(const int& xPosition,const int& yPosition,const Color& color);
        void Update() override;
        void Draw() override;
        ~Block() override = default;

        void UpdateNextPosition(const Vector2Int& inputVector);
        void UpdatePosition();

        Vector2Int& GetPossibleNextPosition();
        const Vector2Int& GetPosition() const;
        void SetHasLanded(bool hasLanded);
        bool HasMoved() const;
        bool HasOccupiedCellOnBoard() const;

    private:

        void UpdateIndex();
    };
}

#endif //BLOCK_H
