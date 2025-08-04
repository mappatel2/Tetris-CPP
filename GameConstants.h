#pragma once
#include "raylib.h"

namespace Tetris::GameConstants {
    constexpr int SCREEN_WIDTH = 1100;
    constexpr int SCREEN_HEIGHT = 1000;

    constexpr int X_CELL_COUNT = 10;
    constexpr int Y_CELL_COUNT = 28;

    constexpr int CELL_SIZE = 40;

    constexpr int TOP_PADDING = -(CELL_SIZE);
    constexpr int LEFT_PADDING = CELL_SIZE * 2;

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
        IBlock,
        JBlock,
        LBlock,
        OBlock,
        SBlock,
        TBlock,
        ZBlock
    };

    inline int GetPositionFromIndex(const int index) {
        return index * CELL_SIZE;
    }

    inline int GetIndexFromPosition(const int position) {
        return position / CELL_SIZE;
    }

    inline Color GetCellColor(const ColorType colorType) {
        switch(colorType) {
            case ColorType::Cyan:
            case ColorType::IBlock:
                return Color(0, 255, 255, 255);
            case ColorType::Blue:
            case ColorType::TBlock:
                return Color(70,130,180, 255);
            case ColorType::Orange:
            case ColorType::LBlock:
                return Color(255,117,24, 255);
            case ColorType::Yellow:
            case ColorType::OBlock:
                return Color(251,236,93, 255);
            case ColorType::Green:
            case ColorType::SBlock:
                return Color(46,111,64, 255);
            case ColorType::Purple:
                return Color(142,69,133, 255);
            case ColorType::Red:
            case ColorType::ZBlock:
                return Color(250,80,83, 255);
            case ColorType::White:
                return Color(255, 255, 255, 255);
            case ColorType::Transparent:
                return Color(0, 0, 0, 0);
            case ColorType::JBlock:
                return Color(128, 0, 128, 255);
            default:
            case ColorType::Black:
                return Color(0, 0, 0, 255);
        }
    }
}
