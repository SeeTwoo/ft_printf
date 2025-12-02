#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(x_tests, mandatory_lohex)
{
	assert_fmt("%x", 0);
	assert_fmt("%x", 1);
	assert_fmt("%x", 10);
	assert_fmt("%x", 16);
	assert_fmt("%x", 20);
}

Test(x_tests, bonus_lohex)
{
	assert_fmt("%.0x", 235796);
	assert_fmt("%.2x", 235796);
	assert_fmt("%.10x", 235796);
	assert_fmt("%2x", 235796);
	assert_fmt("%10x", 235796);
}
/*
Test(X_tests, mandatory_uphex)
{
	assert_fmt("%X", 0);
	assert_fmt("%X", 1);
}

Test(p_tests, mandatory_uphex)
{
	char	c = 'a';

	assert_fmt("%p", NULL);
	assert_fmt("%p", &c);
	assert_fmt("%p", assert_fmt);
}
*/
