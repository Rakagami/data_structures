cmake_minimum_required(VERSION 3.21)
enable_testing()

project(
    data_structures
    VERSION 0.0.1
    DESCRIPTION "Data Structures in C"
    LANGUAGES C
    )

# For blazingly modern C!!
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED On)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)

