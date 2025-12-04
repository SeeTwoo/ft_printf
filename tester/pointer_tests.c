#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

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
	assert_fmt("%+025p", assert_fmt);
	assert_fmt("%p", NULL);
	assert_fmt("%20p", NULL);
	assert_fmt("%020p", NULL);
	assert_fmt("%.0p", NULL);
	assert_fmt("%#.p", NULL);        // '#' ignored
	assert_fmt("%.5p", &c);
	assert_fmt("%10.5p", &c);
	assert_fmt("%-10.5p", &c);
	assert_fmt("%020.10p", &c);
	assert_fmt("%30p", &c);
	assert_fmt("%-30p", &c);
	assert_fmt("%30.15p", &c);
	assert_fmt("%-30.15p", &c);
	assert_fmt("%0p", &c);
	assert_fmt("%010p", &c);
	assert_fmt("%+p", &c);
	assert_fmt("%+ p", &c);
	assert_fmt("% +p", &c);
	assert_fmt("% p", &c);
	assert_fmt("%#+ p", &c);
}
