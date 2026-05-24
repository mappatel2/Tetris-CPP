#ifndef TETRIS_DEBUGPANELUI_H
#define TETRIS_DEBUGPANELUI_H

#include "TetrisCore.h"

namespace Tetris {
    class DebugPanelUI {
    private:
        const Vector2Int k_Anchor = Vector2Int(12, 19);
        const int k_Rows = 5;
        const int k_Columns = 8;
    public:
        DebugPanelUI() = default;
        ~DebugPanelUI() = default;
        void Draw() const;
    };
}

#endif //TETRIS_DEBUGPANELUI_H
