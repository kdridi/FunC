#include "func_close.h"

#ifdef MOCKING
#   define close mock_close
#endif

#include <unistd.h>
#include <stdarg.h>

int func_close(void* p, ...)
{
    va_list ap;

    va_start(ap, p);
    {
        int fd = va_arg(ap, int);
        if ((close(fd)) == -1)
            return (__LINE__);
    }
    va_end(ap);

    return (0);
}