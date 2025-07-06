#include "InputHandler.h"
#include "raylib.h"

namespace Tetris {
    InputHandler::InputHandler() {
        m_LeftMoveAction = std::make_unique<MoveAction>(KEY_LEFT);
        m_RightMoveAction = std::make_unique<MoveAction>(KEY_RIGHT);
        m_DownMoveAction = std::make_unique<MoveAction>(KEY_DOWN);
    }

    void InputHandler::Update() {
        m_LeftMoveAction->Update();
        m_RightMoveAction->Update();
        m_DownMoveAction->Update();
    }
}
