cmake_minimum_required(VERSION 3.8)

set(This AlgorithmsReview)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    linked_list.h
    algoutils.h
    order_statistics.h
    sorting.h
    stack.h
)

set (Sources
    algoutils
    main.cc
    order_statistics.cc
    sorting.cc
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)

add_executable(Main main.cc)
