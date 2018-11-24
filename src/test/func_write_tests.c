#include "func_write.h"

#include <criterion/criterion.h>

static struct
{
    int fd;
    void *buf;
    size_t nbytes;
    size_t result;
} mock;

ssize_t mock_write(int fd, void *buf, size_t nbytes)
{
    mock.fd = fd;
    mock.buf = buf;
    mock.nbytes = nbytes;

    if (mock.fd < 0)
        return (-1);

    return (mock.result);
}

Test(func_write, should_success)
{
    int fd = __LINE__ * (0 + 1);
    void *buf = &fd;
    size_t nbytes = __LINE__;
    size_t result = __LINE__;
    mock.result = __LINE__;
    int err = func_write(&result, fd, buf, nbytes);
    cr_assert_eq(err, 0);
    cr_assert_eq(mock.fd, fd);
    cr_assert_eq(mock.buf, buf);
    cr_assert_eq(mock.nbytes, nbytes);
    cr_assert_eq(result, mock.result);
}

Test(func_write, should_failure)
{
    int fd = __LINE__ * (0 - 1);
    void *buf = &fd;
    size_t nbytes = __LINE__;
    size_t result = __LINE__;
    mock.result = __LINE__;
    int err = func_write(&result, fd, buf, nbytes);
    cr_assert_neq(err, 0);
    cr_assert_eq(mock.fd, fd);
    cr_assert_eq(mock.buf, buf);
    cr_assert_eq(mock.nbytes, nbytes);
}
