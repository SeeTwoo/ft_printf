#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(percent_tests, mandatory_percent)
{
	assert_fmt("%%");
}
