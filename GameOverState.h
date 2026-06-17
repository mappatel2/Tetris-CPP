#ifndef TETRIS_GAMEOVERSTATE_H
#define TETRIS_GAMEOVERSTATE_H

#include "Game.h"
#include "IGameState.h"
#include "InputHandler.h"

namespace Tetris {
    class GameOverState : public IGameState {
    private:
        Game* m_Game;
        InputHandler* m_InputHandler;
    public:

        GameOverState() = delete;
        GameOverState(Game*, InputHandler*);

        void OnEnter() override;
        void OnExit() override;
        void Update() override;
        void HandleInput() override;
        void Draw() override;
        ~GameOverState() override = default;
    };
}

#endif //TETRIS_GAMEOVERSTATE_H
