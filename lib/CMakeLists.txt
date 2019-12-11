# Created by Yael Goldin

add_library(TicTacToeModule STATIC
    src/Spot.cpp
    include/Spot.h
    include/SpotStatus.h)

target_include_directories(TicTacToeModule
    PUBLIC
        include)
