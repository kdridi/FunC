#ifndef _FUNC_MALLOC_H_
#define _FUNC_MALLOC_H_

#ifdef MOCKING
#   define malloc mock_malloc
#endif

#include <stdlib.h>

int func_malloc(void*, ...);

#endif /* _FUNC_MALLOC_H_ */