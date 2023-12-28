#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "utils/asserts.h"

/* Testing Basic creation and usage */
void test_case_0(int argc, const char* argv[])
{
    printf("Starting test case 0\n");

    // Basic initialization
    ll_uint32_t list = ll_new_list_uint32_t();
    ASSERT(list.head == nullptr && list.tail == nullptr, "Initialization failed");
    ll_print_uint32_t(&list);
    ASSERT(ll_is_empty_uint32_t(&list), "Is empty should say list is empty");

    // Append
    ll_add_value_uint32_t(&list, 123);
    ll_add_value_uint32_t(&list, 321);
    ll_add_value_uint32_t(&list, 111);
    ll_add_value_uint32_t(&list, 0);
    ll_print_uint32_t(&list);

    ASSERT(!ll_is_empty_uint32_t(&list), "Is empty should say list is not empty");

    size_t len = ll_length_uint32_t(&list);
    ASSERTF(len == 4, "Wrong length returned %d", len);

    // Get and Set
    Result_uint32_t value_result = ll_get_uint32_t(&list, 2);
    uint32_t value = Result_uint32_t_unwrap(&value_result);
    ASSERTF(value == 111, "Expected value 111 at index 2, got %i instead", value);

    bool ret = ll_set_uint32_t(&list, 2, 31);
    ASSERT(ret, "Setting was not successfull");
    value_result = ll_get_uint32_t(&list, 2);
    value = Result_uint32_t_unwrap(&value_result);
    ASSERT(value == 31, "Expected value 31 at index 2");

    value_result = ll_get_uint32_t(&list, 5);
    ASSERT(Result_uint32_t_is_err(&value_result), "We should have an out of range exception");

    // Deletion
    printf("Deleting value 31\n");
    ll_del_value_uint32_t(&list, 31);
    ll_print_uint32_t(&list);
    printf("Deleting value 42\n");
    ll_del_value_uint32_t(&list, 42);
    ll_print_uint32_t(&list);
    ASSERT(ll_length_uint32_t(&list) == 3, "After deleting, we should have a length of 3");

    value_result = ll_pop_value_uint32_t(&list);
    value = Result_uint32_t_unwrap(&value_result);
    ASSERT(value == 0, "Expected value 0 after popping");
    ASSERT(ll_length_uint32_t(&list) == 2, "After popping, we should have a length of 2");
    ll_print_uint32_t(&list);

    printf("Popping everything\n");
    value_result = ll_pop_value_uint32_t(&list);
    value = Result_uint32_t_unwrap(&value_result);
    ASSERT(value == 321, "After popping, we should get the value 321");
    value_result = ll_pop_value_uint32_t(&list);
    value = Result_uint32_t_unwrap(&value_result);
    ASSERT(value == 123, "After popping, we should get the value 123");
    value_result = ll_pop_value_uint32_t(&list);
    ASSERT(
        Result_uint32_t_is_err(&value_result),
        "After popping an empty list, we should get an error");
    ll_print_uint32_t(&list);

    printf("Adding new values\n");
    ll_add_value_uint32_t(&list, 123);
    ll_add_value_uint32_t(&list, 321);
    ll_add_value_uint32_t(&list, 111);
    ll_add_value_uint32_t(&list, 0);
    ll_print_uint32_t(&list);

    printf("Clearing list\n");
    ll_clear_list_uint32_t(&list);
    ll_print_uint32_t(&list);
}

/* Testing with a lot of numbers */
void test_case_1(int argc, const char* argv[])
{
    const int N = 1000000;

    // Basic initialization
    ll_uint32_t list = ll_new_list_uint32_t();

    printf("Adding %i numbers to list\n", N);

    // Adding the files
    for (uint32_t i = 0; i < N; i++) {
        ll_add_value_uint32_t(&list, i);
    }
    ASSERTF(ll_length_uint32_t(&list) == N, "We should have a list length of %i", N);

    printf("Deleting 1234 12334 42910 1890\n");
    ll_del_value_uint32_t(&list, 1234);
    ll_del_value_uint32_t(&list, 12334);
    ll_del_value_uint32_t(&list, 42910);
    ll_del_value_uint32_t(&list, 1890);

    ASSERTF(ll_length_uint32_t(&list) == N - 4, "We should have a list length of %i", N);

    printf("Clearing...\n");
    ll_clear_list_uint32_t(&list);
    ll_print_uint32_t(&list);
}

int main(int argc, const char* argv[])
{
    printf("Starting Test: LinkedListTest\n");
    ASSERT(argc > 1, "Test executable more than one argument");
    int test_num = atoi(argv[1]);
    switch (test_num) {
    case 0:
        test_case_0(argc, argv);
        exit(EXIT_SUCCESS);
    case 1:
        test_case_1(argc, argv);
        exit(EXIT_SUCCESS);
    default:
        ASSERTF(false, "Invalid test number given %i", test_num);
    }
}
