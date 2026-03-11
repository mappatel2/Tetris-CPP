#include "BlockFactoryManager.h"
#include "TetrisBlock.h"

namespace Tetris {
    BlockFactoryManager::RotationStateArray BlockFactoryManager::GenerateRotations(const bool baseRotation[4][4]) {
        RotationStateArray states = {};
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                states[0][r][c] = baseRotation[r][c];
            }
        }

        for(int i = 1; i < 4; i++) {
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    states[i][c][3-r] = states[i-1][r][c];
                }
            }
        }
        return states;
    }
}