#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

typedef int (*printf_fn)(const char *, ...);
int ft_printf(const char *, ...);

static int run_capture_char(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, char arg)
{
    int fd[2];
    pipe(fd);
    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, arg);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    out[n < 0 ? 0 : n] = '\0';

    return ret;
}

static int run_capture_str(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, const char *arg)
{
    int fd[2];
    pipe(fd);
    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, arg);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    out[n < 0 ? 0 : n] = '\0';

    return ret;
}

static int run_capture_unsigned_int(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, unsigned int val)
{
    int fd[2];
    pipe(fd);
    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, val);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    out[n < 0 ? 0 : n] = '\0';

    return ret;
}

static int run_capture_int(printf_fn fn, char *out, size_t out_size,
                           const char *fmt, int val)
{
    int fd[2];
    pipe(fd);
    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, val);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);
    out[n < 0 ? 0 : n] = '\0';

    return ret;
}

/* Unified assert_fmt with type tag */
typedef enum { FMT_CHAR, FMT_INT, FMT_STR, FMT_U_INT} fmt_type;

static void assert_fmt(fmt_type type, const char *fmt, ...)
{
    char out_sys[1024], out_ft[1024];
    int ret_sys, ret_ft;

    va_list args;
    va_start(args, fmt);

    switch (type) {
        case FMT_CHAR: {
            char arg = (char)va_arg(args, int); // char promoted to int
            ret_sys = run_capture_char(printf, out_sys, sizeof(out_sys), fmt, arg);
            ret_ft  = run_capture_char(ft_printf, out_ft, sizeof(out_ft), fmt, arg);
            break;
        }
        case FMT_INT: {
            int arg = va_arg(args, int);
            ret_sys = run_capture_int(printf, out_sys, sizeof(out_sys), fmt, arg);
            ret_ft  = run_capture_int(ft_printf, out_ft, sizeof(out_ft), fmt, arg);
            break;
        }
        case FMT_STR: {
            const char *arg = va_arg(args, const char *);
            ret_sys = run_capture_str(printf, out_sys, sizeof(out_sys), fmt, arg);
            ret_ft  = run_capture_str(ft_printf, out_ft, sizeof(out_ft), fmt, arg);
            break;
        }
		case FMT_U_INT: {
			unsigned int	val = va_arg(args, unsigned int);
			ret_sys = run_capture_unsigned_int(printf, out_sys, sizeof(out_sys), fmt, val);
			ret_ft = run_capture_unsigned_int(ft_printf, out_ft, sizeof(out_ft), fmt, val);
			break;
		}
    }

    va_end(args);

	cr_expect_eq(ret_sys, ret_ft,
		"Return value mismatch for format \"%s\"\n"
		"printf	: %d\n"
		"ft_printf : %d\n"
		, fmt, ret_sys, ret_ft);
	cr_expect_str_eq(out_sys, out_ft,
		"Output mismatch for format \"%s\"\n"
		"printf : %s\n"
		"ft_printf : %s\n"
		, fmt, out_sys, out_ft);
	//if (ret_sys == ret_ft && strncmp(out_sys, out_ft, ret_sys) == 0)
	//	dprintf(2, "[\e[32mOK\e[0m]\n");
}

/* ------------------------ */
/*         %c TESTS         */
/* ------------------------ */

Test(c_tests, simple_chars)
{
	assert_fmt(FMT_CHAR, "%c", 'a');
	assert_fmt(FMT_CHAR, "%5c", 'a');
	assert_fmt(FMT_CHAR, "%-5c", 'a');
	assert_fmt(FMT_CHAR, "%-5.5c", 'a');
	assert_fmt(FMT_CHAR, "% -5.5c", 'a');
	assert_fmt(FMT_CHAR, "%.0c", 'a');
	assert_fmt(FMT_CHAR, "%0.0c", 'a');
	assert_fmt(FMT_CHAR, "%5.0c", 'a');
}

/* ------------------------ */
/*         %d TESTS         */
/* ------------------------ */

Test(d_tests, simple_integers)
{
    assert_fmt(FMT_INT, "%d", 0);
    assert_fmt(FMT_INT, "%d", -1);
    assert_fmt(FMT_INT, "%d", 1);
    assert_fmt(FMT_INT, "%d", -10);
    assert_fmt(FMT_INT, "%d", 10);
    assert_fmt(FMT_INT, "%d", -100);
    assert_fmt(FMT_INT, "%d", 100);
    assert_fmt(FMT_INT, "%d", -10000);
    assert_fmt(FMT_INT, "%d", 10000);
	assert_fmt(FMT_INT, "%d", 234567);
	assert_fmt(FMT_INT, "%d", -234567);
	assert_fmt(FMT_INT, "%d", INT_MAX);
	assert_fmt(FMT_INT, "%d", INT_MIN);
    assert_fmt(FMT_INT, "%5d", 42);
    assert_fmt(FMT_INT, "%05d", 42);
	assert_fmt(FMT_INT, "%3d", 234567);
	assert_fmt(FMT_INT, "%30d", 234567);
	assert_fmt(FMT_INT, "%-30.3d", 234567);
	assert_fmt(FMT_INT, "%- 30.3d", 234567);
	assert_fmt(FMT_INT, "%-+30.3d", 234567);
	assert_fmt(FMT_INT, "%030.3d", 234567);
	assert_fmt(FMT_INT, "%030.10d", 234567);
}

/* ------------------------ */
/*         %x TESTS         */
/* ------------------------ */

Test(x_tests, lowercase_hex)
{
	assert_fmt(FMT_U_INT, "%x", 0);
	assert_fmt(FMT_U_INT, "%x", 10);
	assert_fmt(FMT_U_INT, "%x", 16);
	assert_fmt(FMT_U_INT, "%x", 17);
	assert_fmt(FMT_U_INT, "%x", 20);
	assert_fmt(FMT_U_INT, "%#x", 20);
/*
	// %30u		160
	// %1u		160
	// %.1		160
	// %.5		160
	// %30.1	160
	// %30.5	160
	// %1.1		160
	// %1.5		160
*/
}

/* ------------------------ */
/*         %X TESTS         */
/* ------------------------ */

Test(X_tests, uppercase_hex)
{
	assert_fmt(FMT_U_INT, "%X", 0);
	assert_fmt(FMT_U_INT, "%X", 10);
	assert_fmt(FMT_U_INT, "%X", 16);
	assert_fmt(FMT_U_INT, "%X", 17);
	assert_fmt(FMT_U_INT, "%X", 20);
	assert_fmt(FMT_U_INT, "%#X", 20);
}

/* ------------------------ */
/*         %u TESTS         */
/* ------------------------ */

Test(u_tests, unsigned_integers)
{
	assert_fmt(FMT_U_INT, "%u", 0);
	assert_fmt(FMT_U_INT, "%u", 1);
	assert_fmt(FMT_U_INT, "%u", 7);
	assert_fmt(FMT_U_INT, "%u", 10);
	assert_fmt(FMT_U_INT, "%u", 13);
	assert_fmt(FMT_U_INT, "%u", 100);
	assert_fmt(FMT_U_INT, "%u", 104);
	assert_fmt(FMT_U_INT, "%u", 158);
	assert_fmt(FMT_U_INT, "%u", 1000);
	assert_fmt(FMT_U_INT, "%u", 1002);
	assert_fmt(FMT_U_INT, "%u", UINT_MAX);
	assert_fmt(FMT_U_INT, "%u", UINT_MAX + 1);
	assert_fmt(FMT_U_INT, "%30u", 3045);
	assert_fmt(FMT_U_INT, "%-30u", 3045);
}

/* ------------------------ */
/*         %s TESTS         */
/* ------------------------ */

Test(s_tests, null_and_basic)
{
    assert_fmt(FMT_STR, "%s", NULL);
    assert_fmt(FMT_STR, "%20s", NULL);
    assert_fmt(FMT_STR, "%-20s", NULL);
    assert_fmt(FMT_STR, "%.2s", NULL);
    assert_fmt(FMT_STR, "%.7s", NULL);
    assert_fmt(FMT_STR, "hello, %s", "world");
    assert_fmt(FMT_STR, "%20s", "hello world");
    assert_fmt(FMT_STR, "%0.2s", "hello world");
}
