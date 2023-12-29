#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "utils/asserts.h"

/* Testing Basic creation and usage*/
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

    // Removing values
    bt_del_value_uint32_t(&tree, 99);
    bt_print_uint32_t(&tree);
    ASSERT(bt_size_uint32_t(&tree) == 6, "Size of tree at this point should be 6");

    // Deleting
    bt_clear_uint32_t(&tree);
    ASSERT(bt_size_uint32_t(&tree) == 0, "Size of tree at this point should be 0");
}

/* Thorough deletion test case for all scenarios */
void test_case_1(int argc, const char* argv[])
{
    printf("Starting test case 1\n");
    bt_uint32_t tree;
    size_t size;

    // Basic initialization
    tree = bt_new_uint32_t();
    ASSERT(tree.root == nullptr, "Initialization failed");
    bt_add_value_uint32_t(&tree, 3);
    ASSERT(!bt_is_empty_uint32_t(&tree), "Is empty should say list is not empty");
    bt_print_uint32_t(&tree);

    // Deleting non-existent
    ASSERT(!bt_del_value_uint32_t(&tree, 99), "Deleting 99 should not be possible at this point");

    // Deleting root
    bt_del_value_uint32_t(&tree, 3);
    ASSERT(bt_is_empty_uint32_t(&tree), "Is empty should say list is empty");
    bt_print_uint32_t(&tree);
    
    // Deleting left swappable
    printf("Deleting left swappable");
    bt_add_value_uint32_t(&tree, 50);
    bt_add_value_uint32_t(&tree, 40);
    bt_add_value_uint32_t(&tree, 30);
    bt_add_value_uint32_t(&tree, 20);
    printf("Before removal of 40\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_del_value_uint32_t(&tree, 40), "Removing 40 was not successfull");

    printf("After removal of 40\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_size_uint32_t(&tree) == 3, "Size of tree at this point should be 3");

    bt_clear_uint32_t(&tree);
    
    // Deleting right swappable
    printf("Deleting right swappable\n");
    bt_add_value_uint32_t(&tree, 20);
    bt_add_value_uint32_t(&tree, 30);
    bt_add_value_uint32_t(&tree, 40);
    bt_add_value_uint32_t(&tree, 50);
    printf("Before removal of 30\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_del_value_uint32_t(&tree, 30), "Removing 30 was not successfull");

    printf("After removal of 30\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_size_uint32_t(&tree) == 3, "Size of tree at this point should be 3");

    bt_clear_uint32_t(&tree);
    
    // Deleting with next bigger swap
    printf("Deleting with next bigger swap");
    bt_add_value_uint32_t(&tree, 50);
    bt_add_value_uint32_t(&tree, 30);
    bt_add_value_uint32_t(&tree, 90);
    bt_add_value_uint32_t(&tree, 80);
    bt_add_value_uint32_t(&tree, 85);
    bt_add_value_uint32_t(&tree, 100);
    bt_add_value_uint32_t(&tree, 99);
    bt_add_value_uint32_t(&tree, 95);
    bt_add_value_uint32_t(&tree, 101);
    printf("Before removal of 90\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_del_value_uint32_t(&tree, 90), "Removing 90 was not successfull");
    
    printf("After removal of 90\n");
    bt_print_uint32_t(&tree);

    ASSERT(bt_size_uint32_t(&tree) == 8, "Size of tree at this point should be 8");

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
    case 1:
        test_case_1(argc, argv);
        exit(EXIT_SUCCESS);
    default:
        ASSERTF(false, "Invalid test case number given %i", test_num);
    }
}
