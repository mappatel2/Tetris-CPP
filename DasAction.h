#pragma once;
#include "InputAction.h"

namespace Tetris {
    class DasAction : public InputAction{
    private:
        static constexpr float DAS_DELAY = 0.334F;
        static constexpr float AUTO_REPEAT_INTERVAL = 0.066F;

        int m_KeyValue;
        bool m_CanExecute;
        bool m_HasMovedOnDasExpiry;
        float m_DasTimer = 0.F;
        float m_AutoRepeatTimer = 0.F;

    public:

        DasAction() = delete;
        ~DasAction() override = default;
        explicit DasAction(int keyValue);

        void Update() override;
        bool CanExecute() const override;
    };
}

