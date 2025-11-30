#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef int (*printf_fn)(const char *, ...);
int ft_vprintf(const char *, va_list ap); 

static int capture_output(int (*vfn)(const char*, va_list),
                          char *out,              /* buffer size must be >= 1024 */
                          const char *fmt,
                          va_list ap)
{
    int fd[2];
    if (pipe(fd) == -1)
        return -1;

    /* Save old stdout and replace with pipe write end */
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) {
        close(fd[0]); close(fd[1]);
        return -1;
    }

    if (dup2(fd[1], STDOUT_FILENO) == -1) {
        close(fd[0]); close(fd[1]); close(saved_stdout);
        return -1;
    }
    close(fd[1]); /* write end now duplicated on STDOUT */

    /* Call target with a copied va_list */
    va_list ap_copy;
    va_copy(ap_copy, ap);
    int ret = vfn(fmt, ap_copy);
    va_end(ap_copy);

    fflush(stdout);

    /* Restore original stdout */
    if (dup2(saved_stdout, STDOUT_FILENO) == -1) {
        /* best effort restore on failure */
    }
    close(saved_stdout);

    /* Read captured data */
    ssize_t n = read(fd[0], out, 1023);
    if (n < 0) n = 0;
    out[n] = '\0';
    close(fd[0]);

    return ret;
}

void assert_fmt(const char *fmt, ...)
{
    char out_sys[1024];
    char out_ft[1024];
    int ret_sys, ret_ft;

    va_list args;
    va_start(args, fmt);

    va_list a1, a2;
    va_copy(a1, args);
    va_copy(a2, args);
    va_end(args);

    ret_sys = capture_output(vprintf, out_sys, fmt, a1);
    va_end(a1);

    ret_ft  = capture_output(ft_vprintf, out_ft, fmt, a2);
    va_end(a2);

    cr_expect_eq(ret_sys, ret_ft,
        "Return mismatch for \"%s\": sys=%d, ft=%d",
        fmt, ret_sys, ret_ft);

    cr_expect_str_eq(out_sys, out_ft,
        "Output mismatch for \"%s\":\nsys=\"%s\"\nft =\"%s\"",
        fmt, out_sys, out_ft);
}

