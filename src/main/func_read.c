#include "func_read.h"

#ifdef MOCKING
#   define read mock_read
#endif

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdarg.h>
#include <assert.h>

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

    *((size_t*) p) = r;

    return (0);
}