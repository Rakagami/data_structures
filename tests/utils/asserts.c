#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "asserts.h"

void ASSERT(bool expression, const char * str) {
    if (!expression) {
        fputs(str, stderr);
        fputs("\n", stderr);
        fflush(stderr);
        exit(1);
    }
}

void ASSERTF(bool expression, const char* fmt, ...)
{
    if (!expression) {
        va_list args;
        va_start(args, fmt);

        vfprintf(stderr, fmt, args);
        fputs("\n", stderr);
        fflush(stderr);
        exit(1);
    }
}
