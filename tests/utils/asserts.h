#include <stdbool.h>

/**
 * @brief: Asserts that expression is true. If false prints msg to stderr and exits
 */
void ASSERT(bool expression, const char* msg);

/**
 * @brief: Asserts that expression is true. If false prints msg to stderr and exits
 * @details: supports formatted string
 */
void ASSERTF(bool expression, const char* fmt, ...);
