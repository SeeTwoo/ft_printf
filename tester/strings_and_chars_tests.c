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

Test(c_tests, mandatory_chars)
{
    assert_fmt("%c", 'a');
    assert_fmt("%c", '\0');
}
