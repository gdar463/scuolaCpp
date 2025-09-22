cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-g3 -Wall -Wextra -Wconversion -Wdouble-promotion
     -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion
     -fsanitize=undefined -fsanitize-trap -DUSING_CMAKE)

project(Scuola VERSION 0.1)

add_executable(Pointers_09-16 Pointers_09-16/main.cpp Pointers_09-16/swap.cpp Pointers_09-16/fill.cpp Pointers_09-16/clamp.cpp)
