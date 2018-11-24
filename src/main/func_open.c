#include "func_open.h"

#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

#define RETURN_TYPE int
#define result (*((RETURN_TYPE*) p))

int func_open(void* p, ...)
{
    va_list ap;
    va_start(ap, p);
        const char* path = va_arg(ap, const char*);
        int oflag = va_arg(ap, int);
        mode_t mode;
        if (oflag & O_CREAT)
            mode = (typeof(mode)) va_arg(ap, int);
    va_end(ap);

    if (oflag & O_CREAT)
        result = open(path, oflag, mode);
    else
        result = open(path, oflag);
    
    assert(result >= -1);

    if (result == -1)
        return (__LINE__);

    return (0);
}