#include <stddef.h>

#include "utils/result_types.h"

#define LL_NODE(type) ll_node_##type

#define LL_NODE_DECLARE(type)                                                                      \
    typedef struct LL_NODE(type) {                                                                 \
        type value;                                                                                \
        struct LL_NODE(type) * next;                                                               \
    } LL_NODE(type);                                                                               \
    LL_NODE(type) * ll_new_list_##type();                                                          \
    bool ll_del_list_##type(LL_NODE(type) * head);                                                 \
    LL_NODE(type) * ll_add_value_##type(LL_NODE(type) * head, const int value);                    \
    LL_NODE(type) * ll_del_value_##type(LL_NODE(type) * head, const int value);                    \
    RESULT(type) ll_pop_value_##type(LL_NODE(type) * head);                                        \
    bool ll_is_empty_##type(LL_NODE(type) * head);                                                 \
    size_t ll_length_##type(LL_NODE(type) * head);                                                 \
    LL_NODE(type) * ll_clear_##type(LL_NODE(type) * head);                                         \
    bool ll_set_##type(LL_NODE(type) * head, const int idx, const int value);                      \
    RESULT(type) ll_get_##type(LL_NODE(type) * head, const int idx);                               \
    void ll_print_##type(LL_NODE(type) * head);

LL_NODE_DECLARE(uint32_t);
