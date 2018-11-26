#include "func_stat.h"

#include <stdarg.h>
#include <assert.h>

int func_stat(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        struct stat* buf = (typeof(buf)) p;
        const char* path = va_arg(ap, const char*);
    va_end(ap);

    int r = stat(path, buf);
    
    assert(r >= -1);
    if (r == -1)
        return (__LINE__);

    return (0);
}