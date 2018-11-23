#include "func_malloc.h"

#ifdef MOCKING
#   define malloc mock_malloc
#endif

#include <stdlib.h>
#include <stdarg.h>

int func_malloc(void* p, ...)
{
    va_list ap;

    va_start(ap, p);
    {
        void** res = (typeof(res)) p;
        
        size_t size = va_arg(ap, size_t);

        if ((*res = malloc(size)) == NULL)
            return (__LINE__);
    }
    va_end(ap);

    return (0);
}