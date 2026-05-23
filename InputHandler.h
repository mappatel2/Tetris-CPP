#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <memory>
#include "DasAction.h"
#include "TriggerAction.h"

namespace Tetris {
    class InputHandler {

    private:

        std::unique_ptr<DasAction> m_LeftMoveAction;
        std::unique_ptr<DasAction> m_RightMoveAction;
        std::unique_ptr<DasAction> m_DownMoveAction;
        std::unique_ptr<TriggerAction> m_UpMoveAction;
        std::unique_ptr<TriggerAction> m_EnableDebugPanelAction;

    public:

        InputHandler();

        void Update() const;

        [[nodiscard]] bool CanExecuteLeft() const {
            return m_LeftMoveAction->CanExecute();
        }

        [[nodiscard]] bool CanExecuteRight() const {
            return m_RightMoveAction->CanExecute();
        }

        [[nodiscard]] bool CanExecuteDown() const {
            return m_DownMoveAction->CanExecute();
        }

        [[nodiscard]] bool CanExecuteUp() const {
            return m_UpMoveAction->CanExecute();
        }

        [[nodiscard]] bool CanExecuteEnableDebugPanel() const {
            return m_EnableDebugPanelAction->CanExecute();
        }
    };


}

#endif
