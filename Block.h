#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"
#include "Vector2Int.h"
#include "raylib.h"
#include <array>

#include "BlockFactoryManager.h"

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

        TetrominoType m_BlockType;
        int m_CurrentRotationStateIndex = 0;
        Color m_Color {};

        bool m_HasMovedX = false;
        bool m_HasMovedY = false;
        bool m_HasLanded = false;
        bool m_OccupyCellOnBoard = false;

    public:

        Block() = default;
        void Update() override;
        void Draw() override;
        ~Block() override = default;

        void UpdateNextPosition(Vector2Int inputVector);
        void UpdatePosition(const std::array<Vector2Int, 4>& nextPositionArr);

        [[nodiscard]] std::array<Vector2Int, 4> GetPossibleNextPositionArr() const;
        [[nodiscard]] std::array<Vector2Int, 4> GetPositionArr() const;
        void SetHasLanded(bool hasLanded);
        [[nodiscard]] bool HasMoved() const;
        [[nodiscard]] bool HasOccupiedCellOnBoard() const;
        Color GetColor() const;

        void UpdateCurrentBlockPositions();
        void UpdateNextBlockPositions();

        void Init(TetrominoType blockType, int xPosition, int yPosition);

    private:

        void UpdateIndex();
        void ResetTimers();
        void ResetFlags();
    };
}

#endif //BLOCK_H
