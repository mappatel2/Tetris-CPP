#include "InputHandler.h"
#include "raylib.h"

namespace Tetris {
    InputHandler::InputHandler() {
        m_LeftMoveAction = std::make_unique<DasAction>(KEY_LEFT);
        m_RightMoveAction = std::make_unique<DasAction>(KEY_RIGHT);
        m_DownMoveAction = std::make_unique<DasAction>(KEY_DOWN);
        m_UpMoveAction = std::make_unique<TriggerAction>(KEY_UP);
        m_EnableDebugPanelAction = std::make_unique<TriggerAction>(KEY_F2);
        m_HardDropAction = std::make_unique<TriggerAction>(KEY_SPACE);
    }

    void InputHandler::Update() const {
        m_LeftMoveAction->Update();
        m_RightMoveAction->Update();
        m_DownMoveAction->Update();
        m_UpMoveAction->Update();
        m_EnableDebugPanelAction->Update();
        m_HardDropAction->Update();
    }
}
