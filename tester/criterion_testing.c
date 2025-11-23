/* tester/test_printf.c */
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ft_printf(const char *, ...);
typedef int (*printf_fn)(const char *, ...);

static int run_capturev(printf_fn fn, char *out, size_t out_size,
                        const char *fmt, va_list args)
{
    int fd[2];
    pipe(fd);

    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, args); // your fn must support va_list version

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    out[n < 0 ? 0 : n] = '\0';

    return ret;
}

static void assert_fmt(const char *fmt, ...)
{
	char	out_sys[1024];
	char	out_ft[1024];
    va_list args;
    va_start(args, fmt);

    va_list args_sys, args_ft;
    va_copy(args_sys, args);
    va_copy(args_ft, args);

    int ret_sys = run_capturev(printf, out_sys, sizeof(out_sys), fmt, args_sys);
    int ret_ft  = run_capturev(ft_printf, out_ft, sizeof(out_ft), fmt, args_ft);

    va_end(args_sys);
    va_end(args_ft);
    va_end(args);

    cr_expect_eq(ret_sys, ret_ft,
        "Return value mismatch for format \"%s\" : "
        "printf=%d ft_printf=%d",
        fmt, ret_sys, ret_ft);

    cr_expect_str_eq(out_sys, out_ft,
        "Output mismatch for format \"%s\" :\n"
        "printf    : \"%s\"\n"
        "ft_printf : \"%s\"",
        fmt, out_sys, out_ft);
}


/* ------------------------ */
/*         %c TESTS         */
/* ------------------------ */

Test(c_tests, simple_chars)
{
	assert_fmt("%c", 'a');
	assert_fmt("%5c", 'a');
	assert_fmt("%-5c", 'a');
	assert_fmt("%-5.5c", 'a');
	assert_fmt("% -5.5c", 'a');
}

/* ------------------------ */
/*         %d TESTS         */
/* ------------------------ */

Test(d_tests, simple_integers)
{
    assert_fmt("%d", 0);
    assert_fmt("%d", -1);
    assert_fmt("%d", 1);
    assert_fmt("%d", -10);
    assert_fmt("%d", 10);
    assert_fmt("%d", -100);
    assert_fmt("%d", 100);
    assert_fmt("%d", -10000);
    assert_fmt("%d", 10000);
	assert_fmt("%d", 234567);
	assert_fmt("%d", -234567);
	assert_fmt("%d", INT_MAX);
	assert_fmt("%d", INT_MIN);
    assert_fmt("%5d", 42);
    assert_fmt("%05d", 42);
	assert_fmt("%3d", 234567);
	assert_fmt("%30d", 234567);
	assert_fmt("%-30.3d", 234567);
	assert_fmt("%- 30.3d", 234567);
	assert_fmt("%-+30.3d", 234567);
	assert_fmt("%030.3d", 234567);
	assert_fmt("%030.10d", 234567);
}

/* ------------------------ */
/*         %s TESTS         */
/* ------------------------ */

Test(s_tests, null_and_basic)
{
    assert_fmt("%s", NULL);
    assert_fmt("%20s", NULL);
    assert_fmt("%-20s", NULL);
    assert_fmt("%.2s", NULL);
    assert_fmt("hello, %s", "world");
    assert_fmt("%20s", "hello world");
    assert_fmt("%0.2s", "hello world");
}
