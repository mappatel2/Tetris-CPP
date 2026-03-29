//
// Created by mapga on 3/29/2026.
//

#include "DasAction.h"
#include "raylib.h"

namespace Tetris {
    DasAction::DasAction(const int keyValue) {
        m_KeyValue = keyValue;
        m_CanExecute = false;
        m_DasTimer = 0.F;
        m_AutoRepeatTimer = 0.F;
        m_HasMovedOnDasExpiry = false;
    }

    void DasAction::Update() {
        //Block Moves immediately to the next block
        if(IsKeyPressed(m_KeyValue)) {
            m_CanExecute = true;
            m_DasTimer = 0.f;
            m_AutoRepeatTimer = 0.f;
            m_HasMovedOnDasExpiry = false;
        }
        else if(IsKeyDown(m_KeyValue)) {

            //Delay Added to not move block continuously after first key press
            if(m_DasTimer <= DAS_DELAY) {
                m_DasTimer += GetFrameTime();
            }
            m_CanExecute = false;

            if(m_DasTimer >= DAS_DELAY) {
                //Move the block after the first key press when DAS Threshold is crossed
                if(!m_HasMovedOnDasExpiry) {
                    m_HasMovedOnDasExpiry = true;
                    m_CanExecute = true;
                }
                //Moves the block after DAS has expired and not block moves at auto repeat rate interval
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

    bool DasAction::CanExecute() const {
        return m_CanExecute;
    }
}
