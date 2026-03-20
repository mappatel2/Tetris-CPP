#pragma once
#include "TetrisCore.h"
#include "Vector2Int.h"
#include <array>

namespace Tetris {
    class PreviewBlockUI {
    private:

        const Vector2Int m_Anchor = Vector2Int(Config::COLUMN_COUNT + 2, Config::VISIBLE_CELL_START_ROW - 1);
        const int m_Rows = 15;
        const int m_Columns = 8;

    public:

        PreviewBlockUI() = default;
        ~PreviewBlockUI() = default;
        void Draw(const std::array<int, 4>&) const;
    };
}
