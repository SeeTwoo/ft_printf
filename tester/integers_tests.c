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
    assert_fmt("%5d", -3407);
    assert_fmt("%8d", -3407);
    assert_fmt("%2d", -3407);
	assert_fmt("%.0d", -3407);
	assert_fmt("%.2d", -3407);
    assert_fmt("%.5d", -3407);
    assert_fmt("%.8d", -3407);
	assert_fmt("%5.0d", -3407);
	assert_fmt("%5.10d", -3407);
	assert_fmt("%15.10d", -3407);
	assert_fmt("%-15.10d", -3407);
	assert_fmt("%0-15.10d", -3407);
	assert_fmt("010d", -3407);
}

Test(u_tests, mandatory_unsigned)
{
    assert_fmt("%u", 0);
    assert_fmt("%u", 1);
    assert_fmt("%u", 10);
    assert_fmt("%u", 306);
    assert_fmt("%u", UINT_MAX);
}

Test(u_tests, bonus_unsigned)
{
    assert_fmt("%5u", 3407);
    assert_fmt("%8u", 3407);
    assert_fmt("%2u", 3407);
	assert_fmt("%.0u", 3407);
	assert_fmt("%.2u", 3407);
    assert_fmt("%.5u", 3407);
    assert_fmt("%.8u", 3407);
	assert_fmt("%5.0u", 3407);
	assert_fmt("%5.10u", 3407);
	assert_fmt("%15.10u", 3407);
	assert_fmt("%-15.10u", 3407);
	assert_fmt("%0-15.10u", 3407);
	assert_fmt("010u", 3407);
}
