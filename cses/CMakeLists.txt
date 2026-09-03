cmake_minimum_required(VERSION 4.0)
project(cses)

set(CMAKE_CXX_STANDARD 20)

add_executable(cses intro/main.cpp
        intro/weird_algorithm.cpp
        intro/missing_number.cpp
        intro/repetitions.cpp
        intro/increasing_array.cpp
        intro/permutations.cpp
        dp/dice_combinations.cpp
        dp/minimizing_coins.cpp
        intro/number_spiral.cpp
        ../aoi/2026/Binomialkoeffizient.cpp
)
