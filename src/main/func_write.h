#ifndef _FUNC_WRITE_H_
#define _FUNC_WRITE_H_

#ifdef MOCKING
#   define write mock_write
#endif

#include <unistd.h>

int func_write(void*, ...);

#endif /* _FUNC_WRITE_H_ */