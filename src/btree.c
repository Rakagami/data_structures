#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

//--------------------------------------------------
// Helper functions

/**
 * @brief Find node that is directly next to the given value
 */
static bt_node_uint32_t* _find_node(bt_uint32_t* tree, const int value)
{
    bt_node_uint32_t *cur = tree->root, *parent;

    if (cur == nullptr) {
        return nullptr;
    }

    parent = cur->parent;
    while (cur != nullptr) {
        parent = cur;
        cur = (value < cur->value) ? cur->left : cur->right;
    }

    return parent;
}

/**
 * @brief Traverse the tree
 *
 * @detail This supports the pre, in and post traversal variant
 *
 * @param node Node to be traversed
 * @param consume Callback to consume node
 * @param variant Variant of traversal (pre=0, in=1, post=2)
 */
static void _traverse_tree(bt_node_uint32_t* node, void (*consume)(bt_node_uint32_t*), int variant)
{
    if (node == nullptr) {
        return;
    }

    if (variant == 0)
        consume(node);
    _traverse_tree(node->left, consume, variant);
    if (variant == 1)
        consume(node);
    _traverse_tree(node->right, consume, variant);
    if (variant == 2)
        consume(node);
}

//--------------------------------------------------

/**
 * @brief Creates a new tree
 */
bt_uint32_t bt_new_uint32_t()
{
    return (bt_uint32_t) { .root = nullptr };
}

/**
 * @brief Adds value to the binary tree
 */
bool bt_add_value_uint32_t(bt_uint32_t* tree, const int value)
{
    bt_node_uint32_t* new_node = malloc(sizeof(bt_node_uint32_t));
    *new_node = (bt_node_uint32_t) {
        .value = value,
        .parent = nullptr,
        .left = nullptr,
        .right = nullptr,
    };

    if (tree->root == nullptr) {
        tree->root = new_node;
        return true;
    } else {
        bt_node_uint32_t* parent_node = _find_node(tree, value);
        if (value < parent_node->value) {
            parent_node->left = new_node;
        } else {
            parent_node->right = new_node;
        }
        new_node->parent = parent_node;
        return true;
    }
}

/**
 * @brief Deletes the first appearance of of value.
 * TODO
 */
bool bt_del_value_uint32_t(bt_uint32_t* tree, const int value)
{
    return true;
}

/**
 * @brief Checks whether value is in the tree
 * TODO
 */
bool bt_contains_uint32_t(bt_uint32_t* tree, const int value)
{
    return true;
}

/**
 * @brief Checks whether tree is empty
 */
bool bt_is_empty_uint32_t(bt_uint32_t* tree)
{
    return tree->root == nullptr;
}

/**
 * @brief Clears tree
 */
static void _free_node(bt_node_uint32_t* node)
{
    free(node);
}
bool bt_clear_uint32_t(bt_uint32_t* tree)
{
    _traverse_tree(tree->root, _free_node, 2);
    tree->root = nullptr;
    return true;
}

/**
 * @brief Counts size of tree
 */
static size_t _size_count = 0;
static void _count_nodes(bt_node_uint32_t* node)
{
    _size_count++;
}
size_t bt_size_uint32_t(bt_uint32_t* tree)
{
    _size_count = 0;
    _traverse_tree(tree->root, _count_nodes, 2);
    return _size_count;
}

/**
 * @brief Prints binary tree
 */
static void _print_node(bt_node_uint32_t* node)
{
    printf("%d ", node->value);
}
static void _print_tree_consume(
    bt_node_uint32_t* node, const int depth, const int ldepth, bool left_child)
{
    for (int i = 0; i < depth - 1; i++) {
        printf("%s   ", (i < (depth - ldepth)) ? " " : "│");
    }
    if (depth > 0) {
        printf("%s─%s ", left_child ? "├" : "└", left_child ? "L" : "R");
    }
    if (node == nullptr) {
        printf("nil\n");
    } else {
        printf("%d\n", node->value);
    }
}
static void _print_tree_traverse(
    bt_node_uint32_t* node, const int depth, const int ldepth, bool left_child)
{
    _print_tree_consume(node, depth, ldepth, left_child);
    if (node == nullptr)
        return;
    int new_ldepth = left_child ? ldepth + 1 : ldepth;
    _print_tree_traverse(node->left, depth + 1, new_ldepth, true);
    _print_tree_traverse(node->right, depth + 1, new_ldepth, false);
}
void bt_print_uint32_t(bt_uint32_t* tree)
{
    printf("------------------------------\n");
    printf("As list:\n");
    printf("[");
    _traverse_tree(tree->root, _print_node, 1);
    printf("]\n");
    printf("As tree:\n");
    _print_tree_traverse(tree->root, 0, 0, true);
    printf("------------------------------\n");
}
