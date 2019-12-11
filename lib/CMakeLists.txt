# Created by Yael Goldin

add_library(lib STATIC
    src/Spot.cpp
    include/Spot.h
    include/SpotStatus.h)

target_include_directories(lib
    PUBLIC
        include)
