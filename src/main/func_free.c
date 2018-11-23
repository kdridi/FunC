#include "func_free.h"

#ifdef MOCKING
#   define free mock_free
#endif

#include <stdlib.h>
#include <stdarg.h>

int func_free(void* p, ...)
{
    va_list ap;

    va_start(ap, p);
    {
        void* ptr = va_arg(ap, void*);
        free(ptr);
    }
    va_end(ap);

    return (0);
}