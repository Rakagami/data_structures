#include "list.h"

#include <stdio.h>
#include <stdlib.h>

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
static ll_node_uint32_t* _find_node_by_value(
    ll_node_uint32_t* head, const uint32_t value, size_t lookback)
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
ll_uint32_t ll_new_list_uint32_t()
{
    return (ll_uint32_t) {
        .head = nullptr,
        .tail = nullptr,
    };
}

/**
 * @brief: Appends the value to the end of the list
 */
bool ll_add_value_uint32_t(ll_uint32_t* list, const int value)
{
    ll_node_uint32_t* new_node = malloc(sizeof(ll_node_uint32_t));
    *new_node = (ll_node_uint32_t) {
        .value = value,
        .next = nullptr,
    };

    if (list->head == nullptr) {
        list->head = new_node;
        list->tail = new_node;
        return true;
    } else {
        ll_node_uint32_t* last_node = list->tail;
        last_node->next = new_node;
        list->tail = new_node;
        return true;
    }
}

/**
 * @brief: Delete the entire list
 */
bool ll_clear_list_uint32_t(ll_uint32_t* list)
{
    ll_node_uint32_t* cur = list->head;
    ll_node_uint32_t* next;
    while (cur != nullptr) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = nullptr;
    list->tail = nullptr;
    return true;
}

/**
 * @brief: Deletes the first appearance of the value
 */
bool ll_del_value_uint32_t(ll_uint32_t* list, const int value)
{
    if (list->head == nullptr) {
        return false;
    } else if (list->head->value == value) {
        uint32_t tmp = list->head->value;
        free(list->head);
        list->head = nullptr;
        return true;
    }

    ll_node_uint32_t* node = _find_node_by_value(list->head, value, 1);
    if (node == nullptr) {
        return false;
    } else if (node->next == nullptr) { // this case shouldn't occur
        return false;
    }

    ll_node_uint32_t* after = node->next->next;
    free(node->next);
    node->next = after;

    return true;
}

/**
 * @brief: Returns whether or not the list is empty
 */
bool ll_is_empty_uint32_t(ll_uint32_t* list)
{
    return list->head == nullptr || list->tail == nullptr;
}

/**
 * @brief: Returns length of the list
 */
size_t ll_length_uint32_t(ll_uint32_t* list)
{
    ll_node_uint32_t* cur = list->head;
    size_t cnt = 0;
    while (cur != nullptr) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

/**
 * @brief: Sets the value at index idx to value
 */
bool ll_set_uint32_t(ll_uint32_t* list, const int idx, const int value)
{
    size_t len = ll_length_uint32_t(list);
    if (idx < 0 || idx >= len) {
        return false;
    }

    ll_node_uint32_t* node = _get_node_by_idx(list->head, idx, 0);
    if (node == nullptr) {
        return false;
    }

    node->value = value;
    return true;
}

/**
 * @brief: Gets value at index idx
 */
Result_uint32_t ll_get_uint32_t(ll_uint32_t* list, const int idx)
{
    size_t len = ll_length_uint32_t(list);
    if (idx < 0 || idx >= len) {
        return Result_uint32_t_Err("Out of range");
    }

    ll_node_uint32_t* node = _get_node_by_idx(list->head, idx, 0);

    if (node == nullptr) {
        return Result_uint32_t_Err("Some error occured");
    } else {
        return Result_uint32_t_Ok(node->value);
    }
}

/**
 * @brief: Pops the last node and returns its value
 */
Result_uint32_t ll_pop_value_uint32_t(ll_uint32_t* list)
{
    if (list->head == nullptr || list->tail == nullptr) { // Empty
        return Result_uint32_t_Err("Trying to pop from empty list");
    } else if (list->head == list->tail || list->head->next == nullptr) { // Only one element
        uint32_t value = list->head->value;
        free(list->head);
        list->head = nullptr;
        list->tail = nullptr;
        return Result_uint32_t_Ok(value);
    } else { // More than one element
        ll_node_uint32_t* cur = list->head;
        ll_node_uint32_t* next = list->head->next;
        while (next->next != nullptr) {
            cur = cur->next;
            next = next->next;
        }
        uint32_t value = next->value;
        free(next);
        cur->next = nullptr;
        list->tail = cur;
        return Result_uint32_t_Ok(value);
    }
}

/**
 * @brief: Gets value at index idx
 */
void ll_print_uint32_t(ll_uint32_t* list)
{
    printf("[");

    ll_node_uint32_t* cur = list->head;
    while (cur != nullptr) {
        printf("%i", cur->value);
        if (cur->next != nullptr)
            printf(", ");
        cur = cur->next;
    }

    printf("]\n");
}
