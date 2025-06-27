cmake_minimum_required(VERSION 3.29)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(raylib)

add_executable(Tetris main.cpp)

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
