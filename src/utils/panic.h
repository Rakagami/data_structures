/**
 * @file panic.h
 * Copied from https://codereview.stackexchange.com/questions/140231/rust-like-result-in-c-nicer-error-handling
 */

/**
 * @brief panics with the error message, terminating the program
 * @details This function never returns. It writes `str` to `stderr` and exits
 *          with an error code of `1`.
 *
 * @param str The error message displayed on termination
 */
void panic(const char* str) __attribute__((noreturn));

/**
 * @brief panics with the error message, terminating the program
 * @details This function never returns. It writes to `stderr` and exits
 *          with an error code of `1`. This function calls `printf` to
 *          allow message formatting
 *
 * @param str The error message displayed on termination
 */
void panicf(const char* fmt, ...) __attribute__((noreturn));
