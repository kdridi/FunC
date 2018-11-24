#ifndef _FUNC_OPEN_H_
#define _FUNC_OPEN_H_

#ifdef MOCKING
#   define open mock_open
#endif

#include <fcntl.h>

int func_open(void*, ...);

#endif /* _FUNC_OPEN_H_ */