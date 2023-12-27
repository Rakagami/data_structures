include(CTest)

# Add test utils library
add_library(utils_test utils/asserts.c)

# Enable Address Sanitizer (ASan) for GCC/Clang
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKEr_FLAGS} -fsanitize=address")

#################
# Add List Tester
#################

add_executable(LinkedListTester test_list.c)
target_include_directories(LinkedListTester PUBLIC "${PROJECT_SOURCE_DIR}/src/")
target_link_libraries(LinkedListTester list_lib utils_test utils_lib)
#set_target_properties(LinkedListTester PROPERTIES COMPILE_FLAGS "")

# List test cases
add_test(NAME LinkedListTester0 COMMAND LinkedListTester 0)
add_test(NAME LinkedListTester1 COMMAND LinkedListTester 1)
add_test(NAME LinkedListTester2 COMMAND LinkedListTester 2)
