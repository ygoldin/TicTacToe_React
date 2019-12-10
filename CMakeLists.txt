# Created by Yael Goldin

cmake_minimum_required(VERSION 3.14)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/WX)
else()
    add_compile_options(-Werror)
    add_compile_options(-Wall)
endif()

add_subdirectory(src)
