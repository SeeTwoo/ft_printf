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
	assert_fmt("%.0x", 0);          // prints nothing
	assert_fmt("%#.0x", 0);         // no "0x"
	assert_fmt("%.1x", 0);
	assert_fmt("%#.1x", 0);
}

Test(X_tests, mandatory_uphex)
{
	assert_fmt("%X", 0);
	assert_fmt("%X", 1);
	assert_fmt("%X", 10);
	assert_fmt("%X", 16);
	assert_fmt("%X", 20);
}

Test(X_tests, bonus_uphex)
{
	assert_fmt("%.0X", 235796);
	assert_fmt("%.2X", 235796);
	assert_fmt("%.10X", 235796);
	assert_fmt("%2X", 235796);
	assert_fmt("%10X", 235796);
}

Test(p_tests, mandatory_pointer)
{
	char	c = 'a';

	assert_fmt("%p", NULL);
	assert_fmt("%p", &c);
	assert_fmt("%p", assert_fmt);
}

Test(p_tests, bonus_pointer)
{
	char	c = 'a';

	assert_fmt("%-50p", NULL);
	assert_fmt("%.50p", &c);
	assert_fmt("%025p", assert_fmt);
}
