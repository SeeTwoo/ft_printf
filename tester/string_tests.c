#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(s_tests, mandatory_strings)
{
    assert_fmt("%s", NULL);
    assert_fmt("%s", "");
    assert_fmt("%s", "hello, world !");
}

Test(s_tests, bonus_string)
{
	assert_fmt("%3s", "");
	assert_fmt("%3.5s", "");
	assert_fmt("%0s", "hello, world !");
	assert_fmt("%0.20s", "hello, world !");
	assert_fmt("%0.2s", "hello, world !");
}
