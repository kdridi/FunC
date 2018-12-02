#include "func_close.h"

#include <stdarg.h>
#include <assert.h>

int func_close(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        int fd = va_arg(ap, int);
    va_end(ap);

    int status = close(fd);

    if (status == -1)
        return (__LINE__);

    assert(status == 0);
    return (0);
}