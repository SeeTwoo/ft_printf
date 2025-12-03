#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(c_tests, mandatory_chars)
{
    assert_fmt("%c", 'a');
    assert_fmt("%c", '\0');
}

Test(c_tests, bonus_chars)
{
	assert_fmt("%5c", 'a');
	assert_fmt("%.5c", 'a');
	assert_fmt("%5c", 'a');
}
