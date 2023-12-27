#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------
// Helper functions

/**
 * @brief Gets linked list node by index
 *
 * @details The lookback value is important since we use a single-linked list. If the lookback is 0,
 *          then the node returned is exactly of index idx. If it's 1, then it actually only returns
 *          the index idx-1. If idx-lookback < 0, then return nullptr.
 *
 * @param head Head of the linked list
 * @param idx Index of node we want to get
 * @param lookback Number of nodes to look back.
 */
static ll_node_uint32_t* _get_node_by_idx(ll_node_uint32_t* head, size_t idx, const size_t lookback)
{
    if (idx - lookback < 0) {
        return nullptr;
    }
    idx = idx - lookback;
    ll_node_uint32_t* cur = head;
    size_t cnt = 0;
    while (cur != nullptr) {
        if (cnt == idx)
            return cur;
        cur = cur->next;
        cnt++;
    }
    return nullptr;
}

/**
 * @brief Gets linked list node by first node appearance
 *
 * @details The lookback value is important since we use a single-linked list. If the lookback is 0,
 *          then the node returned is exactly of the first appearance of value. If it's 1, then it 
 *          actually only returns the lookback-th node before the first appearance of value.
 *
 * @param head Head of the linked list
 * @param idx Index of node we want to get
 * @param lookback Number of nodes to look back.
 */
static ll_node_uint32_t* _find_node_by_value(ll_node_uint32_t* head, const uint32_t value, size_t lookback)
{
    ll_node_uint32_t* cur = head;
    ll_node_uint32_t* lookback_node = head;
    size_t cnt = 0; // Counter to count lookback
    while (cur != nullptr) {
        if (cur->value == value && cnt < lookback)
            return nullptr;
        else if (cur->value == value)
            return lookback_node;

        cur = cur->next;
        if (cnt < lookback) {
            cnt++;
        } else {
            lookback_node = lookback_node->next;
        }
    }
    return nullptr;
}
//--------------------------------------------------

/**
 * @brief: A new list is just the nullptr pointer
 */
ll_node_uint32_t* ll_new_list_uint32_t()
{
    return nullptr;
}

/**
 * @brief: Delete the entire list
 *
 * @details: This basically does the same thing as clear, why did I do this? idk
 */
bool ll_del_list_uint32_t(ll_node_uint32_t* head)
{
    ll_node_uint32_t* cur = head;
    ll_node_uint32_t* next;
    while (cur != nullptr) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    return true;
}

/**
 * @brief: Appends the value to the end of the list
 */
ll_node_uint32_t* ll_add_value_uint32_t(ll_node_uint32_t* head, const int value)
{
    ll_node_uint32_t* new_node = malloc(sizeof(ll_node_uint32_t));
    memset(new_node, 0, sizeof(ll_node_uint32_t));
    new_node->value = value;
    new_node->next = nullptr;

    if (head == nullptr) {
        return new_node;
    } else {
        ll_node_uint32_t* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new_node;
        return head;
    }
}

/**
 * @brief: Deletes the first appearance of the value
 */
ll_node_uint32_t* ll_del_value_uint32_t(ll_node_uint32_t* head, const int value)
{
    if (head == nullptr) {
        return nullptr;
    } else if (head->value == value) {
        uint32_t tmp = head->value;
        free(head);
        return nullptr;
    }

    ll_node_uint32_t * node = _find_node_by_value(head, value, 1);
    if (node == nullptr) {
        return head;
    } else if (node->next == nullptr) { // this case shouldn't occur
        return head;
    }

    ll_node_uint32_t * after = node->next->next;
    free(node->next);
    node->next = after;

    return head;
}

/**
 * @brief: Pops the last node and returns its value
 */
Result_uint32_t ll_pop_value_uint32_t(ll_node_uint32_t* head)
{
    if (head == nullptr) {
        return Result_uint32_t_Err("Trying to pop from empty list");
    } else if (head->next == nullptr) {
        uint32_t value = head->value;
        free(head);
        return Result_uint32_t_Ok(value);
    } else {
        ll_node_uint32_t* cur = head;
        ll_node_uint32_t* next = head->next;
        while (next->next != nullptr) {
            cur = cur->next;
            next = next->next;
        }
        uint32_t value = next->value;
        cur->next = nullptr;
        free(next);
        return Result_uint32_t_Ok(value);
    }
}

/**
 * @brief: Returns whether or not the list is empty
 */
bool ll_is_empty_uint32_t(ll_node_uint32_t* head)
{
    return head == nullptr;
}

/**
 * @brief: Returns length of the list
 */
size_t ll_length_uint32_t(ll_node_uint32_t* head)
{
    ll_node_uint32_t* cur = head;
    size_t cnt = 0;
    while (cur != nullptr) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

/**
 * @brief: Clears the list
 */
ll_node_uint32_t* ll_clear_uint32_t(ll_node_uint32_t* head)
{
    if (ll_del_list_uint32_t(head)) {
        return nullptr;
    } else {
        // Something went wrong in this case.
        return head;
    }
}

/**
 * @brief: Sets the value at index idx to value
 */
bool ll_set_uint32_t(ll_node_uint32_t* head, const int idx, const int value)
{
    size_t len = ll_length_uint32_t(head);
    if (idx < 0 || idx >= len) {
        return false;
    } else if (idx == 0 && head != nullptr) {
        head->value = value;
        return true;
    }

    ll_node_uint32_t * node = _get_node_by_idx(head, idx, 0);
    if (node == nullptr) {
        return false;
    }

    node->value = value;
    return true;
}

/**
 * @brief: Gets value at index idx
 */
Result_uint32_t ll_get_uint32_t(ll_node_uint32_t* head, const int idx)
{
    size_t len = ll_length_uint32_t(head);
    if (idx < 0 || idx >= len) {
        return Result_uint32_t_Err("Out of range");
    }

    for (size_t i = 0; i < len; i++) {
        if (head == nullptr) {
            return Result_uint32_t_Err("Unexpected nullptr node");
        } else if (i == idx) {
            return Result_uint32_t_Ok(head->value);
        } else {
            head = head->next;
        }
    }

    return Result_uint32_t_Ok(0);
}

void ll_print_uint32_t(ll_node_uint32_t* head)
{
    printf("[");

    ll_node_uint32_t* cur = head;
    while (cur != nullptr) {
        printf("%i", cur->value);
        if (cur->next != nullptr)
            printf(", ");
        cur = cur->next;
    }

    printf("]\n");
}
