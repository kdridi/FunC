#include "func_malloc.h"

#include <criterion/criterion.h>

static int err;
static void* res;
static size_t size;
static struct
{
    void* result;
    size_t size;
} mock;

static void setup()
{
    mock.result = NULL;
    mock.size = 0;
    err = 0;
    res = NULL;
    size = 10;
}

static void teardown()
{
    mock.result = NULL;
    mock.size = 0;
    err = 0;
    res = NULL;
    size = 10;
}

void* mock_malloc(size_t size)
{
    mock.size = size;
    return size == 0 ? NULL : mock.result;
}

Test(func_malloc, should_return_OK_when_success, .init = setup, .fini = teardown)
{
    mock.result = func_malloc;
    err = func_malloc(&res, size);
    cr_assert_eq(err, 0);
}

Test(func_malloc, should_return_KO_when_failure, .init = setup, .fini = teardown)
{
    mock.result = NULL;
    err = func_malloc(&res, size);
    cr_assert_neq(err, 0);
}

Test(func_malloc, should_return_NULL_when_0, .init = setup, .fini = teardown)
{
    mock.result = func_malloc;
    func_malloc(&res, 0 * size);
    cr_assert_null(res);
    cr_assert_eq(mock.size, 0);
}

Test(func_malloc, should_return_PTR_when_10, .init = setup, .fini = teardown)
{
    mock.result = func_malloc;
    func_malloc(&res, 1 * size);
    cr_assert_eq(res, func_malloc);
    cr_assert_eq(mock.size, size);
}
