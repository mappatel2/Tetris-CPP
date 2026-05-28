#include "ScoreHelper.h"

namespace Tetris {
    int ScoreHelper::GetScore() const {
        return m_Score;
    }

    void ScoreHelper::OnNotify(GameEvent event) {
        int basePoints = 0;
        switch (event) {
            case GameEvent::Lines_Cleared_1:
                basePoints = 100;
                break;
            case GameEvent::Lines_Cleared_2:
                basePoints = 300;
                break;
            case GameEvent::Lines_Cleared_3:
                basePoints = 500;
                break;
            case GameEvent::Lines_Cleared_4:
                basePoints = 800;
                break;
            case GameEvent::Soft_Drop_Step:
                basePoints = 1;
            default:
                break;
        }
        m_Score += basePoints;
    }
}
