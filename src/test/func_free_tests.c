#include "func_free.h"

#include <criterion/criterion.h>

static int err;
static struct
{
    void* ptr;
} mock;

static void setup()
{
    err = 0;
    mock.ptr = NULL;
}

static void teardown()
{
    err = 0;
    mock.ptr = NULL;
}

void mock_free(void* ptr)
{
    mock.ptr = ptr;
}

Test(func_free, should_return_OK, .init = setup, .fini = teardown)
{
    err = func_free(NULL, func_free);
    cr_assert_eq(err, 0);
}

Test(func_free, should_run_properly, .init = setup, .fini = teardown)
{
    err = func_free(NULL, func_free);
    cr_assert_eq(mock.ptr, func_free);
}
