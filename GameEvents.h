#ifndef TETRIS_GAMEEVENTS_H
#define TETRIS_GAMEEVENTS_H

namespace Tetris {
    enum class GameEvent {
        Lines_Cleared_1,
        Lines_Cleared_2,
        Lines_Cleared_3,
        Lines_Cleared_4,
        Soft_Drop_Step,
        Blocks_Locked,
        Game_Over
    };
}

#endif //TETRIS_GAMEEVENTS_H
