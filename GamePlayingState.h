#ifndef TETRIS_GAMEPLAYINGSTATE_H
#define TETRIS_GAMEPLAYINGSTATE_H

#include "IGameState.h"
#include "InputHandler.h"
#include "Block.h"
#include "Board.h"
#include "DebugPanelUI.h"
#include "ScoreHelper.h"
#include "BlockSpawner.h"

namespace Tetris {

    class Game;

    class GamePlayingState : public IGameState, public Subject {
    private:
        Game* m_Game;
        InputHandler* m_InputHandler;

        Vector2Int m_MovementVector{};

        bool m_WantsToRotate = false;
        bool m_HardDropTriggered = false;
        bool m_EnableDebugPanel = false;
        bool m_CanSpawn = false;
        bool m_HasLanded = false;
        bool m_OccupyCellOnBoard = false;

        float m_MoveDownTimer = 0.f;
        const float m_MoveDownInterval = 0.8f;
        float m_SpawnTimer = 0.F;
        const float m_SpawnInterval = 0.5F;
        float m_HasLandedTimer = 0.f;
        const float m_HasLandedInterval = 0.7F;

        const int m_LockResetLimit = 15;
        int m_LockResets = 0;
        int m_LowestRowReached = 100;

        BlockSpawner* m_BlockSpawner;
        Block* m_Block;
        Board* m_Board;
        DebugPanelUI* m_DebugPanel;
        ScoreHelper* m_ScoreHelper;

    private:

        void InitBlock();
        void UpdateGravity();
        void UpdateBlock();
        void UpdateSpawnLogic();
        void SetBlockHasLandedStatus();
        void UpdateBoard();
        void UpdateLowestRowReached();
        void UpdateGhostPosition() const;
        void RenderDebugPanel() const;

    public:

        GamePlayingState() = delete;
        GamePlayingState(Game*, InputHandler*, BlockSpawner*, Board*, Block*, ScoreHelper*, DebugPanelUI*);

        void OnEnter() override;
        void OnExit() override;
        void HandleInput() override;
        void Update() override;
        void Draw() override;
        ~GamePlayingState() override;
    };
}


#endif //TETRIS_GAMEPLAYINGSTATE_H
