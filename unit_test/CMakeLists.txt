cmake_minimum_required(VERSION 3.8)

set(This GameTests)

set(Sources
    unit_test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Game
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
