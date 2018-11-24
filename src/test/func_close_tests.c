#include "func_close.h"

#include <criterion/criterion.h>

static int err;
static int fd;
static struct
{
    int fd;
} mock;

int mock_close(int fd)
{
    if ((mock.fd = fd) < 0)
        return (-1);
    return (0);
}

Test(func_close, should_success)
{
    fd = __LINE__ * (0 + 1);
    err = func_close(NULL, fd);
    cr_assert_eq(err, 0);
    cr_assert_eq(mock.fd, fd);
}

Test(func_close, should_failure)
{
    fd = __LINE__ * (0 - 1);
    err = func_close(NULL, fd);
    cr_assert_neq(err, 0);
    cr_assert_eq(mock.fd, fd);
}
