#include "ScoreHelper.h"

namespace Tetris {
    int ScoreHelper::GetScore() const {
        return m_Score;
    }

    void ScoreHelper::OnNotify(EventMessage eventMessage) {
        int basePoints = 0;
        switch (eventMessage.type) {
            case EventType::Lines_Cleared_1:
                basePoints = 100;
                break;
            case EventType::Lines_Cleared_2:
                basePoints = 300;
                break;
            case EventType::Lines_Cleared_3:
                basePoints = 500;
                break;
            case EventType::Lines_Cleared_4:
                basePoints = 800;
                break;
            case EventType::Soft_Drop_Step:
                basePoints = 1;
                break;
            case EventType::Hard_Drop:
                basePoints = 2 * eventMessage.value;
            default:
                break;
        }
        m_Score += basePoints;
    }

    void ScoreHelper::Reset() {
        m_Score = 0;
    }
}
