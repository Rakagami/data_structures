cmake_minimum_required(VERSION 3.15)
enable_testing()

project(
    data_structures
    VERSION 0.0.1
    DESCRIPTION "Data Structures in C"
    LANGUAGES C
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)

