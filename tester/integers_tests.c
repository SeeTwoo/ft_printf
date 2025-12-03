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

	assert_fmt("%.0d", 0);          // prints nothing
	assert_fmt("%.1d", 0);
	assert_fmt("%5.0d", 0);         // spaces only
	assert_fmt("%05.0d", 0);
	assert_fmt("%+d", 42);
	assert_fmt("% d", 42);
	assert_fmt("%+d", -42);
	assert_fmt("% d", -42);         // must print "-42"
	assert_fmt("%+8d", 42);
	assert_fmt("% 8d", 42);
	assert_fmt("%+8.5d", 42);
	assert_fmt("% 8.5d", 42);
	assert_fmt("%+08d", 42);        // zero fill after sign
	assert_fmt("% 08d", 42);
	assert_fmt("%08d", 123);
	assert_fmt("%08.5d", 123);      // zero flag ignored due to precision
	assert_fmt("%08.3d", -123);     // sign + precision + zero flag ignored
	assert_fmt("%0.5d", 123);
	assert_fmt("%-10d", 123);
	assert_fmt("%-+10d", 123);
	assert_fmt("%- 10d", 123);
	assert_fmt("%-10.5d", 123);
	assert_fmt("%-10.5d", -123);
	assert_fmt("%20d", 123);
	assert_fmt("%20.10d", 123);
	assert_fmt("%020.10d", 123);    // zero ignored
	assert_fmt("%-30.25d", -123);
	assert_fmt("%.30d", 123);
	assert_fmt("%0-+ 15.10d", 123);
	assert_fmt("%-0+ 15.10d", -123);
	assert_fmt("%+-05d", 123);
	assert_fmt("%-0 15d", 123);
	assert_fmt("%0 15d", 123);      // space + zero
	assert_fmt("%+15d", INT_MAX);
	assert_fmt("%-15d", INT_MAX);
	assert_fmt("%015d", INT_MAX);
	assert_fmt("%+20.15d", INT_MIN);
	assert_fmt("%020.15d", INT_MIN);
	assert_fmt("%-20.15d", INT_MIN);
	assert_fmt("%.10d", -5);
	assert_fmt("%.10d", -12345);
	assert_fmt("%5.10d", -5);
	assert_fmt("%-010d", 42);       // zero ignored
	assert_fmt("%0-10d", 42);       // zero ignored
	assert_fmt("%.d", 42);
	assert_fmt("%.d", 0);           // prints nothing
}
