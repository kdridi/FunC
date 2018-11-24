#include "func_read.h"

#include <stdarg.h>
#include <assert.h>

#define RETURN_TYPE size_t
#define result (*((RETURN_TYPE*) p))

int func_read(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        int fd = va_arg(ap, int);
        void* buf = va_arg(ap, void*);
        size_t nbytes = va_arg(ap, size_t);
    va_end(ap);

    ssize_t r = read(fd, buf, nbytes);
    
    assert(r >= -1);
    if (r == -1)
        return (__LINE__);

    result = r;

    return (0);
}