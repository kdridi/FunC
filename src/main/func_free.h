#ifndef _FUNC_FREE_H_
#define _FUNC_FREE_H_

#ifdef MOCKING
#   define free mock_free
#endif

#include <stdlib.h>

int func_free(void*, ...);

#endif /* _FUNC_FREE_H_ */