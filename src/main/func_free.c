#include "func_free.h"

#include <stdarg.h>

int func_free(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        void* ptr = va_arg(ap, void*);
    va_end(ap);

    free(ptr);

    return (0);
}