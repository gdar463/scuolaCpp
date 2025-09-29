cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-Wall -g -DUSING_CMAKE)

project(Scuola VERSION 0.1)

file(GLOB Pointers_09-16_SRC CONFIGURE_DEPENDS "Pointers_09-16/*.hpp" "Pointers_09-16/*.cpp")
file(GLOB Pointers_09-22_SRC CONFIGURE_DEPENDS "Pointers_09-22/*.hpp" "Pointers_09-22/*.cpp")
file(GLOB Pointers_09-23_SRC CONFIGURE_DEPENDS "Pointers_09-23/*.hpp" "Pointers_09-23/*.cpp")
file(GLOB Struct_2025-10-01_SRC CONFIGURE_DEPENDS "Struct_2025-10-01/*.hpp" "Struct_2025-10-01/*.cpp")

add_executable(Pointers_09-16 ${Pointers_09-16_SRC})
add_executable(Pointers_09-22 ${Pointers_09-22_SRC})
add_executable(Pointers_09-23 ${Pointers_09-23_SRC})
add_executable(Struct_2025-10-01 ${Struct_2025-10-01_SRC})
