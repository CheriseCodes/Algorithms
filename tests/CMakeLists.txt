cmake_minimum_required(VERSION 3.8)

set(This Tests)
set(Sources
    test.cc
)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    AlgorithmsReview
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
