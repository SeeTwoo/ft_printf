#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

typedef int (*printf_fn)(const char *, ...);
int ft_vprintf(const char *, va_list ap); 

static int sys_vprintf_wrapper(const char *fmt, va_list ap)
{
    return vprintf(fmt, ap);
}

static int ft_vprintf_wrapper(const char *fmt, va_list ap)
{
    return ft_vprintf(fmt, ap);
}

static int capture_output(int (*vfn)(const char*, va_list),
                          char *out,
                          const char *fmt,
                          va_list ap)
{
    cr_redirect_stdout();

    va_list ap_copy;
    va_copy(ap_copy, ap);
    int ret = vfn(fmt, ap_copy);
    va_end(ap_copy);

    fflush(stdout);

    const char *captured = cr_get_redirected_stdout();
    strncpy(out, captured, 1023);
    out[1023] = '\0';

    return ret;
}

static void assert_fmt(const char *fmt, ...)
{
    char out_sys[1024];
    char out_ft[1024];
    int ret_sys, ret_ft;

    va_list args;
    va_start(args, fmt);

    // Duplicate arguments for both calls
    va_list a1, a2;
    va_copy(a1, args);
    va_copy(a2, args);
    va_end(args);

    ret_sys = capture_output(sys_vprintf_wrapper, out_sys, fmt, a1);
    va_end(a1);

    ret_ft  = capture_output(ft_vprintf_wrapper, out_ft, fmt, a2);
    va_end(a2);

    cr_expect_eq(ret_sys, ret_ft,
        "Return mismatch for \"%s\": sys=%d, ft=%d",
        fmt, ret_sys, ret_ft);

    cr_expect_str_eq(out_sys, out_ft,
        "Output mismatch for \"%s\":\nsys=\"%s\"\nft =\"%s\"",
        fmt, out_sys, out_ft);
}

Test(d_tests, mandatory_integers)
{
    assert_fmt("%d", 0);
    assert_fmt("%d", -1);
    assert_fmt("%d", 1);
    assert_fmt("%d", INT_MAX);
    assert_fmt("%d", INT_MIN);
}

Test(s_tests, mandatory_strings)
{
    assert_fmt("%s", NULL);
    assert_fmt("%s", "");
    assert_fmt("%s", "hello, world !");
}

Test(c_tests, mandatory_chars)
{
    assert_fmt("%c", 'a');
    assert_fmt("%c", '\0');
}
