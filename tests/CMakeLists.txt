include(CTest)

# Add test utils library
add_library(utils_test utils/asserts.c)

# Enable Address Sanitizer (ASan) for GCC/Clang
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKEr_FLAGS} -fsanitize=address")

#################
# Add List Tester
#################

add_executable(ll_tester test_list.c)
target_include_directories(ll_tester PUBLIC "${PROJECT_SOURCE_DIR}/src/")
target_link_libraries(ll_tester list_lib utils_test utils_lib)

# List test cases
add_test(NAME ll_tester_case_0 COMMAND ll_tester 0)
add_test(NAME ll_tester_case_1 COMMAND ll_tester 1)

#################
# Add Tree Tester
#################

add_executable(bt_tester test_bt.c)
target_include_directories(bt_tester PUBLIC "${PROJECT_SOURCE_DIR}/src/")
target_link_libraries(bt_tester btree_lib utils_test utils_lib)

# List test cases
add_test(NAME bt_tester_case_0 COMMAND bt_tester 0)
add_test(NAME bt_tester_case_1 COMMAND bt_tester 1)
