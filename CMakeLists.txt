cmake_minimum_required(VERSION 4.0)
project(competetive_programming)

set(CMAKE_CXX_STANDARD 14)

add_executable(competetive_programming
        cses/sorting_and_searching/subarray_sum.cpp
        aoi/2026/Binomialkoeffizient.cpp
        cses/dp/dice_combinations.cpp
        cses/dp/minimizing_coins.cpp
        cses/intro/increasing_array.cpp
        cses/intro/main.cpp
        cses/intro/missing_number.cpp
        cses/intro/number_spiral.cpp
        cses/intro/permutations.cpp
        cses/intro/repetitions.cpp
        cses/intro/weird_algorithm.cpp
        cses/sorting_and_searching/subarray_sum_2.cpp
        cses/sorting_and_searching/sum_of_two_values.cpp
)
