#include "func_open.h"

#include <criterion/criterion.h>
#include <fcntl.h>
#include <stdarg.h>

static int err;
static int fd;
static const char* path;
static int oflag;
static mode_t mode;
static struct
{
    int ret;
    const char *path;
    int oflag;
    mode_t mode;
} mock;

static void setup()
{
    err = 0;
    fd = 0;
    mock.path = NULL;
    mock.oflag = 0;
    mock.mode = 0;
    mock.ret = 0;
}

static void teardown()
{
    err = 0;
    fd = 0;
    mock.path = NULL;
    mock.oflag = 0;
    mock.mode = 0;
    mock.ret = 0;
}

int mock_open(const char *path, int oflag, ...)
{
    mock.path = path;
    mock.oflag = oflag;
    mock.mode = 0;
    if (oflag & O_CREAT)
    {
        va_list ap;
        va_start(ap, oflag);
        mock.mode = (typeof(mock.mode)) va_arg(ap, int);
        va_end(ap);
    }
    return (mock.ret);
}

Test(func_open, should_failure, .init = setup, .fini = teardown)
{
    mock.ret = -1;
    path = __FILE__;
    oflag = __LINE__ & ~O_CREAT;
    err = func_open(&fd, path, oflag);
    cr_assert_neq(err, 0);
    cr_assert_str_eq(mock.path, path);
    cr_assert_eq(mock.oflag, oflag);
    cr_assert_eq(mock.mode, 0);
}

Test(func_open, should_failure_on_create, .init = setup, .fini = teardown)
{
    mock.ret = -1;
    path = __FILE__;
    oflag = __LINE__ | O_CREAT;
    mode = __LINE__;
    err = func_open(&fd, path, oflag, mode);
    cr_assert_neq(err, 0);
    cr_assert_str_eq(mock.path, path);
    cr_assert_eq(mock.oflag, oflag);
    cr_assert_eq(mock.mode, mode);
}

Test(func_open, should_success, .init = setup, .fini = teardown)
{
    mock.ret = __LINE__;
    path = __FILE__;
    oflag = __LINE__ & ~O_CREAT;
    err = func_open(&fd, path, oflag);
    cr_assert_eq(err, 0);
    cr_assert_eq(fd, mock.ret);
    cr_assert_str_eq(mock.path, path);
    cr_assert_eq(mock.oflag, oflag);
    cr_assert_eq(mock.mode, 0);
}

Test(func_open, should_success_on_create, .init = setup, .fini = teardown)
{
    mock.ret = __LINE__;
    path = __FILE__;
    oflag = __LINE__ | O_CREAT;
    mode = __LINE__;
    err = func_open(&fd, path, oflag, mode);
    cr_assert_eq(err, 0);
    cr_assert_eq(fd, mock.ret);
    cr_assert_str_eq(mock.path, path);
    cr_assert_eq(mock.oflag, oflag);
    cr_assert_eq(mock.mode, mode);
}
