#include "InputHandler.h"
#include "raylib.h"

namespace Tetris {
    InputHandler::InputHandler() {
        m_InputActions.reserve(8);

        m_LeftMoveAction = std::make_unique<DasAction>(KEY_LEFT);
        m_RightMoveAction = std::make_unique<DasAction>(KEY_RIGHT);
        m_DownMoveAction = std::make_unique<DasAction>(KEY_DOWN);
        m_UpMoveAction = std::make_unique<TriggerAction>(KEY_UP);
        m_EnableDebugPanelAction = std::make_unique<TriggerAction>(KEY_F2);
        m_HardDropAction = std::make_unique<TriggerAction>(KEY_SPACE);
        m_TriggerGameOverAction = std::make_unique<TriggerAction>(KEY_G);
        m_TriggerGameRestartAction = std::make_unique<TriggerAction>(KEY_R);

        m_InputActions.push_back(m_LeftMoveAction.get());
        m_InputActions.push_back(m_RightMoveAction.get());
        m_InputActions.push_back(m_DownMoveAction.get());
        m_InputActions.push_back(m_UpMoveAction.get());
        m_InputActions.push_back(m_EnableDebugPanelAction.get());
        m_InputActions.push_back(m_HardDropAction.get());
        m_InputActions.push_back(m_TriggerGameOverAction.get());
        m_InputActions.push_back(m_TriggerGameRestartAction.get());
    }

    void InputHandler::Update() const {
        for (InputAction* inputAction : m_InputActions) {
            inputAction->Update();
        }
    }
}
