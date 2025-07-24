//
// Created by mapga on 7/6/2025.
//

#include "MoveAction.h"
#include "raylib.h"

namespace Tetris {
    MoveAction::MoveAction(const int keyValue) {
        m_KeyValue = keyValue;
        m_CanExecute = false;
        m_DasTimer = 0.F;
        m_AutoRepeatTimer = 0.F;
        m_HasMovedOnDasExpiry = false;
    }

    void MoveAction::Update() {
        if(IsKeyPressed(m_KeyValue)) {
            m_CanExecute = true;
            m_DasTimer = 0.f;
            m_AutoRepeatTimer = 0.f;
            m_HasMovedOnDasExpiry = false;
        }
        else if(IsKeyDown(m_KeyValue)) {
            m_DasTimer += GetFrameTime();
            m_CanExecute = false;

            if(m_DasTimer >= DAS_DELAY) {
                if(!m_HasMovedOnDasExpiry) {
                    m_HasMovedOnDasExpiry = true;
                    m_CanExecute = true;
                }
                else {
                    m_AutoRepeatTimer += GetFrameTime();
                    if(m_AutoRepeatTimer >= AUTO_REPEAT_INTERVAL) {
                        m_CanExecute  = true;
                        m_AutoRepeatTimer = 0.f;
                    }
                }
            }
        }
        else {
            m_DasTimer = 0.f;
            m_AutoRepeatTimer = 0.f;
            m_CanExecute = false;
            m_HasMovedOnDasExpiry = false;
        }
    }

    bool MoveAction::CanExecute() const {
        return m_CanExecute;
    }
}
