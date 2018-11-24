#include "func_malloc.h"

#include <stdarg.h>

#define RETURN_TYPE void*
#define result (*((RETURN_TYPE*) p))

int func_malloc(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        size_t size = va_arg(ap, size_t);
    va_end(ap);

    result = malloc(size);
    if (result == NULL)
        return (__LINE__);

    return (0);
}