#include "func_free.h"

#include <criterion/criterion.h>

static int err;
static struct
{
    void* ptr;
} free_mock_args;

static void setup()
{
    err = 0;
    free_mock_args.ptr = NULL;
}

static void teardown()
{
    err = 0;
    free_mock_args.ptr = NULL;
}

void mock_free(void* ptr)
{
    free_mock_args.ptr = ptr;
}

Test(func_free, should_return_OK, .init = setup, .fini = teardown)
{
    err = func_free(NULL, func_free);
    cr_assert_eq(err, 0);
}

Test(func_free, should_run_properly, .init = setup, .fini = teardown)
{
    err = func_free(NULL, func_free);
    cr_assert_eq(free_mock_args.ptr, func_free);
}
