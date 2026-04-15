cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SRC_test_sorts timecounter.cpp time_sorts.cpp)
add_executable(time_sorts ${SRC_test_sorts})

add_executable(test_bubble test_bubble.cpp)
add_test(NAME bubblesort COMMAND test_bubble)

add_executable(test_insertion test_insertion.cpp)
add_test(NAME insertionsort COMMAND test_insertion)

add_executable(test_selection test_selection.cpp)
add_test(NAME selectionsort COMMAND test_selection)

enable_testing()