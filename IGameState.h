#ifndef TETRIS_IGAMESTATE_H
#define TETRIS_IGAMESTATE_H

namespace Tetris {
    class IGameState {
    public:
        virtual void OnEnter() = 0;
        virtual void OnExit() = 0;
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual ~IGameState() = default;
    };
}

#endif //TETRIS_IGAMESTATE_H
