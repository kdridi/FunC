#include "func_stat.h"

#include <criterion/criterion.h>
#include <string.h>

static struct
{
    const char* path;
    struct stat buf;
    int result;
} mock;

int mock_stat(const char* path, struct stat* buf)
{
    mock.path = path;
    memcpy(buf, &mock.buf, sizeof(*buf));

    if (path)
        return (mock.result);

    return (-1);
}

Test(func_stat, should_success)
{
    const char* path = NULL;

    struct stat buf;
    buf.st_size = 0;

    mock.buf.st_size = __LINE__;
    mock.result = __LINE__;

    int err = func_stat(&buf, path);
    cr_assert_neq(err, 0);
    cr_assert_eq(mock.path, path);
    cr_assert_eq(mock.buf.st_size, buf.st_size);
}

Test(func_stat, should_failure)
{
    const char* path = __FILE__;

    struct stat buf;
    buf.st_size = 0;

    mock.buf.st_size = __LINE__;
    mock.result = __LINE__;

    int err = func_stat(&buf, path);
    cr_assert_eq(err, 0);
    cr_assert_str_eq(mock.path, path);
    cr_assert_eq(mock.buf.st_size, buf.st_size);
}
