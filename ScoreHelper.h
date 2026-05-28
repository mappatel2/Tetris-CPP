#ifndef TETRIS_SCOREHELPER_H
#define TETRIS_SCOREHELPER_H

namespace Tetris {
    class ScoreHelper {
    private:
        int m_Score = 0;
    public:
        void UpdateScore(int linesCleared);
        [[nodiscard]] int GetScore() const;
    };
}

#endif //TETRIS_SCOREHELPER_H
