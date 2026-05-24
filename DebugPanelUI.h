#ifndef TETRIS_DEBUGPANELUI_H
#define TETRIS_DEBUGPANELUI_H

#include "TetrisCore.h"
#include <string>
#include <vector>

namespace Tetris {

    struct DebugEntry {
        const char* label;
        std::string value;
    };

    class DebugPanelUI {
    private:

        const Vector2Int k_Anchor = Vector2Int(12, 19);
        const int k_Rows = 5;
        const int k_Columns = 8;

    public:

        DebugPanelUI() = default;
        ~DebugPanelUI() = default;
        void Draw(std::initializer_list<DebugEntry>) const;

    };
}

#endif //TETRIS_DEBUGPANELUI_H
