#ifndef _FUNC_CLOSE_H_
#define _FUNC_CLOSE_H_

#ifdef MOCKING
#   define close mock_close
#endif

#include <unistd.h>

int func_close(void*, ...);

#endif /* _FUNC_CLOSE_H_ */