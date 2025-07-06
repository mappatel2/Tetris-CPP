#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <memory>
#include "MoveAction.h"

namespace Tetris {
    class InputHandler {

    private:

        std::unique_ptr<MoveAction> m_LeftMoveAction;
        std::unique_ptr<MoveAction> m_RightMoveAction;
        std::unique_ptr<MoveAction> m_DownMoveAction;

    public:

        InputHandler();

        void Update();

        bool CanMoveLeft() const {
            return m_LeftMoveAction->CanExecute();
        }

        bool CanMoveRight() const {
            return m_RightMoveAction->CanExecute();
        }

        bool CanMoveDown() const {
            return m_DownMoveAction->CanExecute();
        }
    };


}

#endif
