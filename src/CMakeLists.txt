# Created by Yael Goldin

add_library(TicTacToeModule STATIC
    module/Spot.cpp
    module/Spot.h
    module/SpotStatus.h)

target_include_directories(TicTacToeModule
    PUBLIC
        module)
