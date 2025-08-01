cmake_minimum_required(VERSION 3.29)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(raylib)

add_executable(Tetris main.cpp
        Entity.h
        Game.cpp
        Game.h
        GameConstants.h
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        Block.cpp
        Block.h
        InputHandler.cpp
        InputHandler.h
        MoveAction.cpp
        MoveAction.h
        Vector2Int.h
        TetrisBlock.cpp
        TetrisBlock.h
        TetrisBlockFactory.h
        TetrisBlockFactory.cpp
        Tetris_Blocks/ITetrisBlock.cpp
        Tetris_Blocks/ITetrisBlock.h
        Tetris_Blocks/OTetrisBlock.cpp
        Tetris_Blocks/OTetrisBlock.h
        Tetris_Blocks/TTetrisBlock.cpp
        Tetris_Blocks/TTetrisBlock.h
        Tetris_Blocks/STetrisBlock.cpp
        Tetris_Blocks/STetrisBlock.h
        Tetris_Blocks/ZTetrisBlock.cpp
        Tetris_Blocks/ZTetrisBlock.h
        Tetris_Blocks/LTetrisBlock.cpp
        Tetris_Blocks/LTetrisBlock.h
        Tetris_Blocks/JTetrisBlock.cpp
        Tetris_Blocks/JTetrisBlock.h)

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
