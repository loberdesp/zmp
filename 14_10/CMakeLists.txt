cmake_minimum_required(VERSION 4.1)
project(14_10)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

add_executable(14_10 main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
)
