cmake_minimum_required(VERSION 3.17)
project(Problem_2_Assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(Problem_2_Assignment_1
        include/Fraction.h
        src/Fraction.cpp
        main.cpp src/FractionCalculator.cpp include/FractionCalculator.h)
