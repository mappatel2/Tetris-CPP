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

        Vector2Int m_CornerPosition = {};
        std::array<Vector2Int, 4> m_PositionArr {};
        std::array<Vector2Int, 4> m_PossibleNextPositionArr {};
        std::array<bool, 4> m_IsVisibleArr {};
        std::array<int, 4> m_RowIndexArr {};
        std::array<int, 4> m_ColumnIndexArr {};

        TetrominoType m_BlockType;
        int m_ProspectiveRotationStateIndex = 0;
        int m_CurrentRotationStateIndex = 0;
        Color m_Color {};

    public:

        Block() = default;
        void Update() override {}
        void Draw() override;
        ~Block() override = default;

        void UpdateNextPosition(Vector2Int inputVector);
        void MoveBy(Vector2Int moveVector);

        [[nodiscard]] std::array<Vector2Int, 4> GetPossibleNextPositionArr() const;
        [[nodiscard]] std::array<Vector2Int, 4> GetPositionArr() const;
        [[nodiscard]] Color GetColor() const;

        void UpdateCurrentRotationIndex();
        void UpdateNextRotationIndex();

        void Init(TetrominoType blockType, int xPosition, int yPosition);

    private:

        void UpdateIndex();
        void UpdateCurrentBlockPositions(int rotationStateIndex);

    };
}

#endif //BLOCK_H
