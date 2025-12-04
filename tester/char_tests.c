#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);

Test(c_tests, mandatory_chars)
{
    assert_fmt("%c", 'a');
    assert_fmt("%c", '\0');
}

Test(c_tests, no_precision)
{
	assert_fmt("%c", 'a');
	assert_fmt("%0c", 'a');
	assert_fmt("%1c", 'a');
	assert_fmt("%5c", 'a');
}

Test(c_tests, zero_precision)
{
	assert_fmt("%.0c", 'a');
	assert_fmt("%0.0c", 'a');
	assert_fmt("%1.0c", 'a');
	assert_fmt("%5.0c", 'a');
}

Test(c_tests, one_precision)
{
	assert_fmt("%.1c", 'a');
	assert_fmt("%0.1c", 'a');
	assert_fmt("%1.1c", 'a');
	assert_fmt("%5.1c", 'a');
}

Test(c_tests, large_precision)
{
	assert_fmt("%.5c", 'a');
	assert_fmt("%0.5c", 'a');
	assert_fmt("%1.5c", 'a');
	assert_fmt("%5.5c", 'a');
}

//==================================================================
//   left justify
//==================================================================

Test(c_tests, l_no_precision)
{
	assert_fmt("%-c", 'a');
	assert_fmt("%-0c", 'a');
	assert_fmt("%-1c", 'a');
	assert_fmt("%-5c", 'a');
}

Test(c_tests, l_zero_precision)
{
	assert_fmt("%-.0c", 'a');
	assert_fmt("%-0.0c", 'a');
	assert_fmt("%-1.0c", 'a');
	assert_fmt("%-5.0c", 'a');
}

Test(c_tests, l_one_precision)
{
	assert_fmt("%-.1c", 'a');
	assert_fmt("%-0.1c", 'a');
	assert_fmt("%-1.1c", 'a');
	assert_fmt("%-5.1c", 'a');
}

Test(c_tests, l_large_precision)
{
	assert_fmt("%-.5c", 'a');
	assert_fmt("%-0.5c", 'a');
	assert_fmt("%-1.5c", 'a');
	assert_fmt("%-5.5c", 'a');
}

//right
	// a character
		// no precision
			// no width
			// 0 width
			// right width
			// large width
		// 0 precision
		// enough precision
		// large precision

//left
