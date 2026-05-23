#pragma once
#include "InputAction.h"

namespace Tetris {
    class TriggerAction : public InputAction{
    private:
        static constexpr float DEBOUNCE_TIME = 0.1F;
        int m_KeyValue;
        bool m_CanExecute;
        float m_DebounceTimer;

    public:

        TriggerAction() = delete;
        ~TriggerAction() override = default;
        explicit TriggerAction(int keyValue);

        void Update() override;
        [[nodiscard]] bool CanExecute() const override;
    };
}
