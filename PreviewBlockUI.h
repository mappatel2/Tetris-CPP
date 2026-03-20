#pragma once
#include "TetrisCore.h"
#include "Vector2Int.h"

namespace Tetris {
    class PreviewBlockUI {
    private:

        constexpr Vector2Int m_Anchor = Vector2Int(Config::COLUMN_COUNT + 2, Config::ROW_COUNT - 1);
        constexpr int m_Rows = 21;
        constexpr int m_Columns = 8;

    public:

        PreviewBlockUI() = default;
        ~PreviewBlockUI() = default;
        void Draw() const;
    };
}
