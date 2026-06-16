cmake_minimum_required(VERSION 3.29)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(raylib)

add_executable(Tetris main.cpp
        Entity.h
        Game.cpp
        Game.h
        TetrisCore.h
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        Block.cpp
        Block.h
        InputHandler.cpp
        InputHandler.h
        Vector2Int.h
        BlockFactoryManager.h
        PreviewBlockUI.cpp
        PreviewBlockUI.h
        BlockFactoryManager.cpp
        InputAction.h
        DasAction.cpp
        DasAction.h
        TriggerAction.cpp
        TriggerAction.h
        BlockSpawner.cpp
        BlockSpawner.h
        DebugPanelUI.cpp
        DebugPanelUI.h
        ResourceManager.h
        ResourceManager.cpp
        ScoreHelper.cpp
        ScoreHelper.h
        GameEvents.h
        Observer.h
        Subject.h
        ScorePanelUI.cpp
        ScorePanelUI.h
        IGameState.h
        GamePlayingState.cpp
        GamePlayingState.h
        GameOverState.cpp
        GameOverState.h)

target_include_directories(Tetris PRIVATE raylib/src)
target_link_libraries(Tetris PRIVATE raylib_static)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#if (WIN32)
add_custom_command(TARGET Tetris POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:raylib>
    $<TARGET_FILE_DIR:Tetris>
)
#endif()
