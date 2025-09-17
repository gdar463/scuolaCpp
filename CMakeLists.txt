cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-g3 -Wall -Wextra -Wconversion -Wdouble-promotion
     -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion
     -fsanitize=undefined -fsanitize-trap)

project(Scuola VERSION 0.1)

add_executable(Pointers Pointers/main.cpp Pointers/swap.cpp Pointers/fill.cpp Pointers/clamp.cpp)
