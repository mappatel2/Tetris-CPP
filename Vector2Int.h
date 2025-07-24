#pragma once

namespace Tetris {
    struct Vector2Int {
        int x;
        int y;

        Vector2Int() {
            x = y = 0;
        }

        Vector2Int(const int x, const int y) :
         x {x} , y{y} { }

        Vector2Int(const Vector2Int& other) = default;

        void Update(const int x, const int y) {
            this->x = x;
            this->y = y;
        }

        void Update(const Vector2Int& other) {
            this->x = other.x;
            this->y = other.y;
        }

        Vector2Int operator+(const Vector2Int& rhs) const {
            return {x + rhs.x, y + rhs.y};
        }

        Vector2Int operator-(const Vector2Int& rhs) const {
            return {x - rhs.x, y - rhs.y};
        }

        Vector2Int operator* (const Vector2Int& rhs) const {
            return {x * rhs.x, y * rhs.y};
        }
    };
}