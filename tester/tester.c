#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	ft_printf(const char *, ...);

typedef int (*printf_fn)(const char *, ...);

int run_test(printf_fn fn, char *out, size_t out_size,
             const char *fmt, const char *str)
{
    int fd[2];
    pipe(fd);

    int saved = dup(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);

    int ret = fn(fmt, str);

    fflush(stdout);
    dup2(saved, STDOUT_FILENO);
    close(saved);

    ssize_t n = read(fd[0], out, out_size - 1);
    close(fd[0]);

    if (n < 0)
        n = 0;

    out[n] = '\0';

    return ret;
}

void compare_with(const char *fmt, const char *str)
{
    char buf_printf[1024];
    char buf_ft[1024];

    int ret_printf = run_test(printf,     buf_printf, sizeof(buf_printf), fmt, str);
    int ret_ft     = run_test(ft_printf,  buf_ft,     sizeof(buf_ft),     fmt, str);

    int ret_mismatch  = (ret_printf != ret_ft);
    int out_mismatch  = (strcmp(buf_printf, buf_ft) != 0);

    if (!ret_mismatch && !out_mismatch) {
		fprintf(stderr, "\e[32mOK\e[0m\n");
        return;
	}

    fprintf(stderr,
        "=== TEST FAILED ===\n"
        "Format : \"%s\"\n"
        "Arg    : \"%s\"\n",
        fmt, str
    );

    if (ret_mismatch)
        fprintf(stderr,
            "Return value mismatch:\n"
            "    printf     -> %d\n"
            "    ft_printf  -> %d\n",
            ret_printf, ret_ft
        );

    if (out_mismatch)
        fprintf(stderr,
            "Output mismatch:\n"
            "    printf     -> \"%s\"\n"
            "    ft_printf  -> \"%s\"\n",
            buf_printf, buf_ft
        );
}

int	main(void) {
	compare_with(NULL, NULL);
	compare_with("", NULL);
	compare_with("%s\n", NULL);
	compare_with("hello, %s\n", "world");
	compare_with("%20s\n", "hello world");
	compare_with("%0s\n", "hello world");
	compare_with("%-0s\n", "hello world");
	compare_with("%0.2s\n", "hello world");
	return (0);
}
