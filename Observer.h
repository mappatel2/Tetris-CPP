#ifndef TETRIS_OBSERVER_H
#define TETRIS_OBSERVER_H

#include "GameEvents.h"

namespace Tetris {
    class Observer {
    public:
        virtual ~Observer() = default;
        virtual void OnNotify(EventMessage eventMsg) = 0;
    };
}

#endif //TETRIS_OBSERVER_H
