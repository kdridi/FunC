#ifndef _FUNC_READ_H_
#define _FUNC_READ_H_

#ifdef MOCKING
#   define read mock_read
#endif

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int func_read(void*, ...);

#endif /* _FUNC_READ_H_ */