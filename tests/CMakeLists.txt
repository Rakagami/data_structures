include(CTest)

add_executable(LinkedListTester test_list.c)

target_include_directories(LinkedListTester PUBLIC "${PROJECT_SOURCE_DIR}/src/")
target_link_libraries(LinkedListTester list_lib)

add_test(NAME LinkedListTester0 
            COMMAND LinkedListTester 0)

add_test(NAME LinkedListTester1 
            COMMAND LinkedListTester 1)

        #set_tests_properties(LinkedListTester1 
        #                     PROPERTIES DEPENDS ctest_build_test_code)

#set_property(TEST LinkedListTester PROPERTY )
