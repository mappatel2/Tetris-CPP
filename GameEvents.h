#ifndef TETRIS_GAMEEVENTS_H
#define TETRIS_GAMEEVENTS_H

namespace Tetris {
    enum class EventType {
        Lines_Cleared_1,
        Lines_Cleared_2,
        Lines_Cleared_3,
        Lines_Cleared_4,
        Soft_Drop_Step,
        Hard_Drop,
        Blocks_Locked,
        Game_Over
    };

    struct EventMessage {
        EventType type;
        int value;
    };
}

#endif //TETRIS_GAMEEVENTS_H
