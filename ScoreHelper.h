#ifndef TETRIS_SCOREHELPER_H
#define TETRIS_SCOREHELPER_H

#include "Observer.h"

namespace Tetris {
    class ScoreHelper : public Observer{
    private:
        int m_Score = 0;
    public:
        void OnNotify(EventMessage) override;
        [[nodiscard]] int GetScore() const;
    };
}

#endif //TETRIS_SCOREHELPER_H
