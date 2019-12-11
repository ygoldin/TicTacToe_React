# Created by Yael Goldin

add_executable(tests)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

target_sources(tests
    PRIVATE
        TestSpot.cpp
)

target_link_libraries(tests lib gtest gtest_main)