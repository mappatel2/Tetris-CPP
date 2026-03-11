#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"
#include "Vector2Int.h"
#include "raylib.h"
#include <array>
#include <memory>
#include "TetrisBlock.h"

namespace Tetris {
    class Block : public Entity {

    private:

        float m_MoveDownTimer = 0.f;
        float m_HasLandedTimer = 0.f;
        const float m_HasLandedInterval = 0.7F;
        const float m_MoveDownInterval = 0.8f;

        Vector2Int m_CornerPosition = {};
        std::array<Vector2Int, 4> m_PositionArr {};
        std::array<Vector2Int, 4> m_PossibleNextPositionArr {};
        std::array<bool, 4> m_IsVisibleArr {};
        std::array<int, 4> m_RowIndexArr {};
        std::array<int, 4> m_ColumnIndexArr {};

        Color m_Color {};
        std::unique_ptr<TetrisBlock> m_TetrisBlock = nullptr;

        bool m_HasMovedX = false;
        bool m_HasMovedY = false;
        bool m_HasLanded = false;
        bool m_OccupyCellOnBoard = false;

    public:

        Block() = default;
        void Update() override;
        void Draw() override;
        ~Block() override = default;

        void UpdateNextPosition(const Vector2Int& inputVector);
        void UpdatePosition();

        std::array<Vector2Int, 4>& GetPossibleNextPositionArr();
        const std::array<Vector2Int, 4>& GetPositionArr() const;
        void SetHasLanded(bool hasLanded);
        bool HasMoved() const;
        bool HasOccupiedCellOnBoard() const;
        Graphics::ColorType GetColorType() const;

        void Init(std::unique_ptr<TetrisBlock> tetrisBlock, const int& xPosition, const int& yPosition);

    private:

        void UpdateIndex();
        void ResetTimers();
        void ResetFlags();
    };
}

#endif //BLOCK_H
