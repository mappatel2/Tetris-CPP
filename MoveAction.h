#pragma once

namespace Tetris {
    class MoveAction {
    private:
        static constexpr float DAS_DELAY = 0.334F;
        static constexpr float AUTO_REPEAT_INTERVAL = 0.066F;

        int m_KeyValue;
        bool m_CanExecute;
        bool m_HasMovedOnDasExpiry;
        float m_DasTimer = 0.F;
        float m_AutoRepeatTimer = 0.F;

    public:

        MoveAction() = delete;
        explicit MoveAction(int keyValue);
        void Update();
        ~MoveAction() = default;

        bool CanExecute() const;
    };
};
