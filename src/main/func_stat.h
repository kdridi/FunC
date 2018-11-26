#ifndef _FUNC_STAT_H_
#define _FUNC_STAT_H_

#ifdef MOCKING
#   define stat mock_stat
#endif

#include <sys/stat.h>

int func_stat(void*, ...);

#endif /* _FUNC_STAT_H_ */