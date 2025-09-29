cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-Wall -g -DUSING_CMAKE -O0)

project(Scuola VERSION 0.1)

file(GLOB Pointers_09-16_SRC CONFIGURE_DEPENDS "Pointers_09-16/*.hpp" "Pointers_09-16/*.cpp")
file(GLOB Pointers_09-22_SRC CONFIGURE_DEPENDS "Pointers_09-22/*.hpp" "Pointers_09-22/*.cpp")
file(GLOB Pointers_09-23_SRC CONFIGURE_DEPENDS "Pointers_09-23/*.hpp" "Pointers_09-23/*.cpp")
file(GLOB Struct_2025-09-29_SRC CONFIGURE_DEPENDS "Struct_2025-09-29/*.hpp" "Struct_2025-09-29/*.cpp")

add_executable(Pointers_09-16 ${Pointers_09-16_SRC})
set_target_properties(Pointers_09-16 PROPERTIES OUTPUT_NAME "pointers_09-16")
add_executable(Pointers_09-22 ${Pointers_09-22_SRC})
set_target_properties(Pointers_09-22 PROPERTIES OUTPUT_NAME "pointers_09-22")
add_executable(Pointers_09-23 ${Pointers_09-23_SRC})
set_target_properties(Pointers_09-16 PROPERTIES OUTPUT_NAME "pointers_09-23")
add_executable(Struct_2025-09-29 ${Struct_2025-09-29_SRC})
set_target_properties(Struct_2025-09-29 PROPERTIES OUTPUT_NAME "struct_2025-09-29")
