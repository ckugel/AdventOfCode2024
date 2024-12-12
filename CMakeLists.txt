cmake_minimum_required(VERSION 3.28)
project(AdventOfCode2024)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(AdventOfCode2024
        src/DayOne.cpp
        src/DayOne.h
        src/main.cpp
        src/DayTwo.h
        src/DayTwo.cpp
        src/DayThree.cpp
        src/DayFour.cpp)
