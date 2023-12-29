# List Library
add_library(list_lib list.c)

# Tree Library
add_library(btree_lib btree.c)

# Utils
add_library(utils_lib utils/panic.c utils/result_types.c)
add_executable(result_example result_example.c)

target_link_libraries(result_example PRIVATE utils_lib)
