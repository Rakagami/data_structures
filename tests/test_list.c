#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "utils/asserts.h"

/* Testing Basic creation */
void test_case_0()
{
    printf("Starting test case 0\n");

    ll_node_uint32_t * list = ll_new_list_uint32_t();
    ASSERT(list == NULL, "Initialization failed");
    ll_print_uint32_t(list);

    list = ll_add_value_uint32_t(list, 123);
    list = ll_add_value_uint32_t(list, 321);
    list = ll_add_value_uint32_t(list, 111);
    list = ll_add_value_uint32_t(list, 0);
    ll_print_uint32_t(list);

    size_t len = ll_length_uint32_t(list);
    ASSERTF(len == 4, "Wrong length returned %d", len);

    ll_clear_uint32_t(list);
}

void test_case_1()
{
    printf("Starting test case 1\n");
}

void test_case_2()
{
    printf("Starting test case 2\n");
}

int main(int argc, const char* argv[])
{
    printf("Starting Test: LinkedListTest\n");
    ASSERT(argc > 1, "Test executable more than one argument");
    int test_num = atoi(argv[1]);
    switch (test_num) {
    case 0:
        test_case_0();
        exit(EXIT_SUCCESS);
    case 1:
        test_case_1();
        exit(EXIT_SUCCESS);
    case 2:
        test_case_2();
        exit(EXIT_SUCCESS);
    default:
        ASSERTF(false, "Invalid test number given %i", test_num);
    }
}
