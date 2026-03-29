#include "TriggerAction.h"
#include "raylib.h"

namespace Tetris {
    TriggerAction::TriggerAction(const int keyValue) {
        m_KeyValue = keyValue;
        m_CanExecute = false;
        m_DebounceTimer = 0.F;
    }

    void TriggerAction::Update() {
        m_CanExecute = false;

        if(m_DebounceTimer > 0.F) {
            m_DebounceTimer -= GetFrameTime();
            return;
        }

        if(IsKeyPressed(m_KeyValue)) {
            m_DebounceTimer = DEBOUNCE_TIME;
            m_CanExecute = true;
        }
    }

    bool TriggerAction::CanExecute() const {
        return m_CanExecute;
    }
}
