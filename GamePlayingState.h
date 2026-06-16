#ifndef TETRIS_GAMEPLAYINGSTATE_H
#define TETRIS_GAMEPLAYINGSTATE_H

#include "IGameState.h"
#include "Game.h"
#include "InputHandler.h"

namespace Tetris {
    class GamePlayingState : public IGameState{
    private:
        Game* m_Game;
        InputHandler* m_InputHandler;

    public:
        GamePlayingState() = delete;
        GamePlayingState(Game*, InputHandler*);
        void HandleInput() override;
        void Update() override;
        void Draw() override;
        ~GamePlayingState() override = default;
    };
}


#endif //TETRIS_GAMEPLAYINGSTATE_H
