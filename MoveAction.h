#ifndef MOVEACTION_H
#define MOVEACTION_H

namespace Tetris {
    class MoveAction {
    private:
        static constexpr float DAS_DELAY = 0.167F;
        static constexpr float AUTO_REPEAT_INTERVAL = 0.033F;

        int m_KeyValue;
        bool m_CanExecute;
        bool m_HasMovedOnDasExpiry;
        float m_DasTimer = 0.F;
        float m_AutoRepeatTimer = 0.F;

    public:

        MoveAction() = delete;
        MoveAction(int keyValue);
        void Update();
        ~MoveAction() = default;

        bool CanExecute() const {
            return m_CanExecute;
        }
    };
};

#endif //MOVEACTION_H
