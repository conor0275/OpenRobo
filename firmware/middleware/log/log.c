#include "log.h"
#include <stdio.h>
#include <stdarg.h>

void log_info(const char *fmt, ...)
{
    char buffer[128];

    va_list args;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    printf("%s", buffer);
}