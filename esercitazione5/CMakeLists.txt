cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -O3")


add_executable(time_sorts time_sorts.cpp timecounter.cpp)


add_executable(test_merge test_merge.cpp)
add_test(NAME mergesort COMMAND test_merge)

add_executable(test_quick test_quick.cpp)
add_test(NAME quicksort COMMAND test_quick)

add_executable(test_hybrid test_hybrid.cpp)
add_test(NAME hybridsort COMMAND test_hybrid)
enable_testing()
