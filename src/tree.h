#include <stddef.h>
#include <stdint.h>

/**
 * @file tree.h
 *
 * Binary tree variants.
 *
 */

/**
 * @brief B-Tree (Binary Tree)
 */
#define B_TREE(type) bt_##type

#define B_TREE_NODE(type) bt_node_##type

#define B_TREE_DECLARE(type)                                                                       \
    typedef struct B_TREE_NODE(type) {                                                             \
        type value;                                                                                \
        struct B_TREE_NODE(type) * parent;                                                         \
        struct B_TREE_NODE(type) * left;                                                           \
        struct B_TREE_NODE(type) * right;                                                          \
    } B_TREE_NODE(type);                                                                           \
    typedef struct B_TREE(type) {                                                                  \
        B_TREE_NODE(type) * root;                                                                  \
    } B_TREE(type);                                                                                \
    B_TREE(type) bt_new_##type();                                                                  \
    bool bt_add_value_##type(B_TREE(type) * tree, const int value);                                \
    bool bt_del_value_##type(B_TREE(type) * tree, const int value);                                \
    bool bt_contains_##type(B_TREE(type) * tree, const int value);                                 \
    bool bt_is_empty_##type(B_TREE(type) * tree);                                                  \
    bool bt_clear_##type(B_TREE(type) * tree);                                                     \
    size_t bt_size_##type(B_TREE(type) * tree);                                                    \
    void bt_print_##type(B_TREE(type) * tree);

B_TREE_DECLARE(uint32_t);
