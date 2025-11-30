#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(x_tests, mandatory_lohex)
{
	assert_fmt("%x", 0);
	assert_fmt("%x", 1);
}

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
