#include "func_write.h"

#ifdef MOCKING
#   define write mock_write
#endif

#include <unistd.h>
#include <stdarg.h>
#include <assert.h>

int func_write(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        int fd = va_arg(ap, int);
        void* buf = va_arg(ap, void*);
        size_t nbytes = va_arg(ap, size_t);
    va_end(ap);

    ssize_t r = write(fd, buf, nbytes);
    
    assert(r >= -1);
    if (r == -1)
        return (__LINE__);

    *((size_t*) p) = r;

    return (0);
}