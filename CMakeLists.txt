cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c)

add_subdirectory(libs)
target_link_libraries(untitled1 data_structures)
target_link_libraries(untitled1 algorithms)

add_library(str string/string_.h
        string/string_.c)

add_library(oas libs/data_structures/ordered_array_set/ordered_array_set.h
        libs/data_structures/ordered_array_set/ordered_array_set.c)

target_link_libraries(untitled1 str)
target_link_libraries(untitled1 oas)