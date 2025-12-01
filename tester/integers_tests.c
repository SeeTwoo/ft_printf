#include <criterion/criterion.h>
#include <stdarg.h>
#include <limits.h>

void	assert_fmt(const char *fmt, ...);

Test(d_tests, mandatory_integers)
{
    assert_fmt("%d", 0);
    assert_fmt("%d", -1);
    assert_fmt("%d", 1);
    assert_fmt("%d", INT_MAX);
    assert_fmt("%d", INT_MIN);
}

Test(d_tests, bonus_integers)
{
    assert_fmt("%5d", 0);
    assert_fmt("%.5d", 0);
    assert_fmt("%5d", 1);
    assert_fmt("%.5d", 1);
	assert_fmt("%.0d", 1);
	assert_fmt("%5.0d", 1);
}

Test(u_tests, mandatory_unsigned)
{
    assert_fmt("%u", 0);
    assert_fmt("%u", 1);
    assert_fmt("%u", 10);
    assert_fmt("%u", 306);
    assert_fmt("%u", UINT_MAX);
}
