#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "panic.h"

void panic(const char* str)
{
    fputs(str, stderr);
    exit(1);
}

void panicf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    vfprintf(stderr, fmt, args);

    exit(1);
}
