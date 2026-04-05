#pragma once

#include <iostream>

namespace Tetris {
    struct Vector2Int {
        int x;
        int y;

        constexpr Vector2Int() {
            x = y = 0;
        }

        constexpr Vector2Int(const int x, const int y) :
         x {x} , y{y} { }

        void Update(const int xParam, const int yParam) {
            this->x = xParam;
            this->y = yParam;
        }

        void Update(const Vector2Int& other) {
            this->x = other.x;
            this->y = other.y;
        }

        Vector2Int& operator+= (const Vector2Int rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Vector2Int& operator-= (const Vector2Int rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        Vector2Int& operator*= (const Vector2Int rhs) {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }

        Vector2Int& operator*= (const int rhs) {
            x *= rhs;
            y *= rhs;
            return *this;
        }
    };

    constexpr std::ostream& operator<<(std::ostream& os, const Vector2Int& rhs) {
        os << "[ " << rhs.x << ", " << rhs.y << " ]";
        return os;
    }

    constexpr Vector2Int operator+(Vector2Int lhs, const Vector2Int rhs) {
        return lhs += rhs;
    }

    constexpr Vector2Int operator-(Vector2Int lhs, const Vector2Int rhs) {
        return lhs -= rhs;
    }

    constexpr Vector2Int operator*(Vector2Int lhs, Vector2Int rhs) {
        return lhs *= rhs;
    }
}
