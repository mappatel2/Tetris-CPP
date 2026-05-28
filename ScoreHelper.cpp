#include "ScoreHelper.h"

namespace Tetris {
    int ScoreHelper::GetScore() const {
        return m_Score;
    }

    void ScoreHelper::UpdateScore(int linesCleared) {
        if (linesCleared < 0) return;
        int scoreToAdd = 0;
        if (linesCleared == 1) {
            scoreToAdd = 100;
        }
        else if (linesCleared == 2) {
            scoreToAdd = 300;
        }
        else if (linesCleared == 3) {
            scoreToAdd = 500;
        }
        else if (linesCleared == 4) {
            scoreToAdd = 800;
        }
        m_Score += scoreToAdd;
    }
}
