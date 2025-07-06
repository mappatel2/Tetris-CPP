#pragma once

namespace Tetris {
    class Entity {
    public:
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual ~Entity() = default;
    };
}