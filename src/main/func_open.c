#include "func_open.h"

#ifdef MOCKING
#   define open mock_open
#endif

#include <fcntl.h>
#include <stdarg.h>

int func_open(void* p, ...)
{
    va_list ap;

    va_start(ap, p);
    {
        int* fd = (typeof(fd)) p;
        const char* path = va_arg(ap, const char*);
        int oflag = va_arg(ap, int);
        if (oflag & O_CREAT)
        {
            mode_t mode = (typeof(mode)) va_arg(ap, int);
            if ((*fd = open(path, oflag, mode)) == -1)
                return (__LINE__);
        }
        else if ((*fd = open(path, oflag)) == -1)
            return (__LINE__);
    }
    va_end(ap);

    return (0);
}