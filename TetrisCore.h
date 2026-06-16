#pragma once
#include "raylib.h"
#include "Vector2Int.h"

namespace Tetris {

    enum class TetrominoType {
        I, J, L, O, S, T, Z
    };

    enum class GameState {
        Playing,
        GameOver
    };

    inline const char* ToString(const TetrominoType type) {
        switch (type) {
            case TetrominoType::I: return "I";
            case TetrominoType::J: return "J";
            case TetrominoType::L: return "L";
            case TetrominoType::O: return "O";
            case TetrominoType::S: return "S";
            case TetrominoType::T: return "T";
            case TetrominoType::Z: return "Z";
            default: return "Check ToString Function";
        }
    }

    inline std::string ToString(const int val) {
        return std::to_string(val);
    }

    inline std::string ToString(const float val) {
        return std::to_string(val);
    }

    inline const char* ToString(const bool val) {
        return val ? "True" : "False";
    }

    namespace Config {
        constexpr int SCREEN_WIDTH = 1100;
        constexpr int SCREEN_HEIGHT = 1000;

        constexpr int X_CELL_COUNT = 10;
        constexpr int Y_CELL_COUNT = 28;

        constexpr int CELL_SIZE = 40;

        constexpr int TOP_PADDING = -(CELL_SIZE);
        constexpr int LEFT_PADDING = CELL_SIZE * 2;

        constexpr int ROW_COUNT = 24;
        constexpr int COLUMN_COUNT = 10;
        constexpr int VISIBLE_CELL_START_ROW = 4;
        constexpr int VISIBLE_CELL_START_COLUMN = 0;

        constexpr int START_ROW_INDEX = 2;
        constexpr int START_COLUMN_INDEX = 1;
    }

    namespace Graphics {

        enum class ColorType {
            Transparent,
            White,
            Black,
            Cyan,
            Blue,
            Orange,
            Yellow,
            Green,
            Purple,
            Red,
            Error
        };

        // Returns a specific color based on the color type
        inline Color GetCellColor(const ColorType colorType) {
            switch(colorType) {
                case ColorType::Cyan:
                    return Color(0, 255, 255, 255);
                case ColorType::Blue:
                    return Color(70,130,180, 255);
                case ColorType::Orange:
                    return Color(255,117,24, 255);
                case ColorType::Yellow:
                    return Color(251,236,93, 255);
                case ColorType::Green:
                    return Color(46,111,64, 255);
                case ColorType::Purple:
                    return Color(142,69,133, 255);
                case ColorType::Red:
                    return Color(250,80,83, 255);
                case ColorType::White:
                    return Color(255, 255, 255, 255);
                case ColorType::Transparent:
                    return Color(0, 0, 0, 0);
                case ColorType::Error:
                    return Color(255, 0, 255, 255);
                default:
                case ColorType::Black:
                    return Color(0, 0, 0, 255);
            }
        }

        inline Color GetTetrominoColor(const TetrominoType type) {
            switch(type) {
                case TetrominoType::I:
                    return GetCellColor(ColorType::Cyan);
                case TetrominoType::J:
                    return Color(128, 0, 128, 255);
                case TetrominoType::L:
                    return GetCellColor(ColorType::Orange);
                case TetrominoType::O:
                    return GetCellColor(ColorType::Yellow);
                case TetrominoType::S:
                    return GetCellColor(ColorType::Green);
                case TetrominoType::T:
                    return GetCellColor(ColorType::Blue);
                case TetrominoType::Z:
                    return GetCellColor(ColorType::Red);
                default:
                    return GetCellColor(ColorType::Error);
            }
        }
    }

    namespace GridConfig {

        inline int IndexToScreenPosition(const int index) {
            return index * Config::CELL_SIZE;
        }

        inline Vector2Int IndexToScreenPosition(const Vector2Int index) {
            return index * Config::CELL_SIZE;
        }

        inline int ScreenPositionToIndex(const int position) {
            return position / Config::CELL_SIZE;
        }

        // Returns the Row Position for an Index
        inline int GetRowPositionFromIndex(const int rowIndex) {
            return IndexToScreenPosition(rowIndex) + Config::TOP_PADDING;
        }

        inline int GetColumnPositionFromIndex(const int colIndex) {
            return IndexToScreenPosition(colIndex) + Config::LEFT_PADDING;
        }

        inline int GetRowIndexFromPosition(const int rowPosition) {
            return ScreenPositionToIndex(rowPosition - Config::TOP_PADDING);
        }

        inline int GetColumnIndexFromPosition(const int columnPosition) {
            return ScreenPositionToIndex(columnPosition - Config::LEFT_PADDING);
        }
    }
}