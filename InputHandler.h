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

    public:

        InputHandler();

        void Update() const;

        bool CanExecuteLeft() const {
            return m_LeftMoveAction->CanExecute();
        }

        bool CanExecuteRight() const {
            return m_RightMoveAction->CanExecute();
        }

        bool CanExecuteDown() const {
            return m_DownMoveAction->CanExecute();
        }

        bool CanExecuteUp() const {
            return m_UpMoveAction->CanExecute();
        }
    };


}

#endif
