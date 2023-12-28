#include <stddef.h>

#include "utils/result_types.h"

#define LL(type) ll_##type

#define LL_NODE(type) ll_node_##type

#define LL_DECLARE(type)                                                                           \
    typedef struct LL_NODE(type) {                                                                 \
        type value;                                                                                \
        struct LL_NODE(type) * next;                                                               \
    } LL_NODE(type);                                                                               \
    typedef struct LL(type) {                                                                      \
        LL_NODE(type) * head;                                                                      \
        LL_NODE(type) * tail;                                                                      \
    } LL(type);                                                                                    \
    LL(type) ll_new_list_##type();                                                                 \
    bool ll_add_value_##type(LL(type) * list, const int value);                                    \
    bool ll_clear_list_##type(LL(type) * list);                                                    \
    bool ll_del_value_##type(LL(type) * list, const int value);                                    \
    bool ll_is_empty_##type(LL(type) * list);                                                      \
    size_t ll_length_##type(LL(type) * list);                                                      \
    bool ll_set_##type(LL(type) * list, const int idx, const int value);                           \
    RESULT(type) ll_get_##type(LL(type) * list, const int idx);                                    \
    RESULT(type) ll_pop_value_##type(LL(type) * list);                                             \
    void ll_print_##type(LL(type) * list);

LL_DECLARE(uint32_t);
