#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "utils/asserts.h"

/* Testing Basic creation and usage */
void test_case_0(int argc, const char* argv[])
{
    printf("Starting test case 0\n");
    bt_uint32_t tree;
    size_t size;

    // Basic initialization
    tree = bt_new_uint32_t();
    ASSERT(tree.root == nullptr, "Initialization failed");
    bt_print_uint32_t(&tree);
    ASSERT(bt_is_empty_uint32_t(&tree), "Is empty should say list is empty");

    // Adding values
    bt_add_value_uint32_t(&tree, 3);
    bt_add_value_uint32_t(&tree, 0);
    bt_add_value_uint32_t(&tree, 132);
    bt_add_value_uint32_t(&tree, 180);
    bt_add_value_uint32_t(&tree, 99);
    bt_print_uint32_t(&tree);
    ASSERT(bt_size_uint32_t(&tree) == 5, "Size of tree at this point should be 5");

    // Adding values again
    bt_add_value_uint32_t(&tree, 132);
    bt_add_value_uint32_t(&tree, 80);
    bt_print_uint32_t(&tree);
    ASSERT(bt_size_uint32_t(&tree) == 7, "Size of tree at this point should be 7");

    // Deleting
    bt_clear_uint32_t(&tree);
    ASSERT(bt_size_uint32_t(&tree) == 0, "Size of tree at this point should be 0");
}

int main(int argc, const char* argv[])
{
    printf("Starting Test: BTreeTester\n");
    ASSERT(argc > 1, "Test executable needs more than one argument");
    int test_num = atoi(argv[1]);
    switch (test_num) {
    case 0:
        test_case_0(argc, argv);
        exit(EXIT_SUCCESS);
    default:
        ASSERTF(false, "Invalid test case number given %i", test_num);
    }
}
