/* tester/test_printf.c */
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ft_printf(const char *, ...);
typedef int (*printf_fn)(const char *, ...);

static int run_capture_str(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, const char *arg)
{
    int fd[2];
    if (pipe(fd) != 0)
        return -1;

    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, arg);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    if (n < 0) n = 0;
    out[n] = '\0';

    return ret;
}

static int run_capture_int(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, int val)
{
    int fd[2];
    if (pipe(fd) != 0)
        return -1;

    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, val);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    if (n < 0) n = 0;
    out[n] = '\0';

    return ret;
}

/* String-based assertion */
static void assert_fmt_s(const char *fmt, const char *arg)
{
    char out_sys[1024];
    char out_ft[1024];
    int ret_sys = run_capture_str(printf, out_sys, sizeof(out_sys), fmt, arg);
    int ret_ft  = run_capture_str(ft_printf, out_ft, sizeof(out_ft), fmt, arg);

    cr_expect_eq(ret_sys, ret_ft,
        "Return value mismatch for format \"%s\" with arg \"%s\": "
        "printf=%d ft_printf=%d",
        fmt, arg ? arg : "(null)", ret_sys, ret_ft);

    cr_expect_str_eq(out_sys, out_ft,
        "Output mismatch for format \"%s\" with arg \"%s\":\n"
        "printf    : \"%s\"\n"
        "ft_printf : \"%s\"",
        fmt, arg ? arg : "(null)", out_sys, out_ft);
}

/* Integer-based assertion */
static void assert_fmt_d(const char *fmt, int val)
{
    char out_sys[1024];
    char out_ft[1024];
    int ret_sys = run_capture_int(printf, out_sys, sizeof(out_sys), fmt, val);
    int ret_ft  = run_capture_int(ft_printf, out_ft, sizeof(out_ft), fmt, val);

    cr_expect_eq(ret_sys, ret_ft,
        "Return value mismatch for format \"%s\" with arg %d: "
        "printf=%d ft_printf=%d",
        fmt, val, ret_sys, ret_ft);

    cr_expect_str_eq(out_sys, out_ft,
        "Output mismatch for format \"%s\" with arg %d:\n"
        "printf    : \"%s\"\n"
        "ft_printf : \"%s\"",
        fmt, val, out_sys, out_ft);
}

/* ------------------------ */
/*         %s TESTS         */
/* ------------------------ */

Test(s_tests, null_and_basic)
{
    assert_fmt_s("%s\n", NULL);
    assert_fmt_s("%20s\n", NULL);
    assert_fmt_s("%-20s\n", NULL);
    assert_fmt_s("%.2s\n", NULL);
    assert_fmt_s("hello, %s\n", "world");
    assert_fmt_s("%20s\n", "hello world");
    assert_fmt_s("%0.2s\n", "hello world");
}

/* ------------------------ */
/*         %d TESTS         */
/* ------------------------ */

Test(d_tests, simple_integers)
{
    assert_fmt_d("%d\n", 0);
    assert_fmt_d("%d\n", -1);
    assert_fmt_d("%d\n", 1);
    assert_fmt_d("%5d\n", 42);
    assert_fmt_d("%05d\n", 42);
}
