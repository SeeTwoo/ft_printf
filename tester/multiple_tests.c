#include <criterion/criterion.h>
#include <stdarg.h>
#include <limits.h>

void	assert_fmt(const char *fmt, ...);

Test(multiple_tests, basic_combination)
{
	char	s[] = "hello";

	assert_fmt("%s and %p and %c and %d\n", s, &s[0], s[0], s[0]);
	assert_fmt("%c and %s and %d\n", s[0], s[0], s);
}
