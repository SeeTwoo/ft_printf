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

//negative
Test(d_tests, null_no_precision)
{
	assert_fmt("%d", -579103);
	assert_fmt("%0d", -579103);
	assert_fmt("%2d", -579103);
	assert_fmt("%6d", -579103);
	assert_fmt("%8d", -579103);
	assert_fmt("%08d", -579103);
}

Test(d_tests, null_zero_precision)
{
	assert_fmt("%.0d", -579103);
	assert_fmt("%0.0d", -579103);
	assert_fmt("%2.0d", -579103);
	assert_fmt("%6.0d", -579103);
	assert_fmt("%8.0d", -579103);
	assert_fmt("%08.0d", -579103);
}

Test(d_tests, null_little_precision)
{
	assert_fmt("%.2d", -579103);
	assert_fmt("%0.2d", -579103);
	assert_fmt("%2.2d", -579103);
	assert_fmt("%6.2d", -579103);
	assert_fmt("%8.2d", -579103);
	assert_fmt("%08.2d", -579103);
}

Test(d_tests, null_right_precision)
{
	assert_fmt("%.6d", -579103);
	assert_fmt("%0.6d", -579103);
	assert_fmt("%2.6d", -579103);
	assert_fmt("%6.6d", -579103);
	assert_fmt("%8.6d", -579103);
	assert_fmt("%08.6d", -579103);
}

Test(d_tests, null_large_precision)
{
	assert_fmt("%.8d", -579103);
	assert_fmt("%0.8d", -579103);
	assert_fmt("%2.8d", -579103);
	assert_fmt("%02.8d", -579103);
	assert_fmt("%6.8d", -579103);
	assert_fmt("%06.8d", -579103);
	assert_fmt("%8.8d", -579103);
	assert_fmt("%08.8d", -579103);
}

//zero
Test(d_tests, empty_no_precision)
{
	assert_fmt("%d", 0);
	assert_fmt("%+d", 0);
	assert_fmt("%-d", 0);
	assert_fmt("%0d", 0);
	assert_fmt("%-0d", 0);
	assert_fmt("%+0d", 0);
	assert_fmt("%2d", 0);
	assert_fmt("%02d", 0);
	assert_fmt("%+2d", 0);
	assert_fmt("%+02d", 0);
	assert_fmt("%-2d", 0);
	assert_fmt("%-02d", 0);
}

Test(d_tests, emtpy_zero_precision)
{
	assert_fmt("%.0d", 0);
	assert_fmt("%0.0d", 0);
	assert_fmt("%2.0d", 0);
}

Test(d_tests, emtpy_little_precision)
{
	assert_fmt("%.2d", 0);
	assert_fmt("%0.2d", 0);
	assert_fmt("%2.2d", 0);
}

//positive
Test(d_tests, string_no_precision)
{
	assert_fmt("%d", 234789);
	assert_fmt("%0d", 223948);
	assert_fmt("%2d", 229384);
	assert_fmt("%6d", 234890);
	assert_fmt("%8d", 234890);
}

Test(d_tests, string_zero_precision)
{
	assert_fmt("%.0d", 234980);
	assert_fmt("%0.0d", 329384);
	assert_fmt("%2.0d", 234098);
	assert_fmt("%6.0d", 209843);
	assert_fmt("%8.0d", 134578);
}

Test(d_tests, string_zero_precisoin)
{
	assert_fmt("%.2d", 134578);
	assert_fmt("%0.2d", 134578);
	assert_fmt("%2.2d", 134578);
	assert_fmt("%6.2d", 134578);
	assert_fmt("%8.2d", 134578);
}

Test(d_tests, string_right_precision)
{
	assert_fmt("%.6d", 134578);
	assert_fmt("%0.6d", 134578);
	assert_fmt("%2.6d", 134578);
	assert_fmt("%6.6d", 134578);
	assert_fmt("%8.6d", 134578);
}

Test(d_tests, string_large_precision)
{
	assert_fmt("%.8d", 134578);
	assert_fmt("%0.8d", 134578);
	assert_fmt("%2.8d", 134578);
	assert_fmt("%6.8d", 134578);
	assert_fmt("%8.8d", 134578);
}

//==========================================================
/////left justification
//==========================================================


//negative
Test(d_tests, l_null_no_precision)
{
	assert_fmt("%-d", -579103);
	assert_fmt("%-0d", -579103);
	assert_fmt("%-2d", -579103);
	assert_fmt("%-6d", -579103);
	assert_fmt("%-8d", -579103);
}

Test(d_tests, l_null_zero_precision)
{
	assert_fmt("%-.0d", -579103);
	assert_fmt("%-0.0d", -579103);
	assert_fmt("%-2.0d", -579103);
	assert_fmt("%-6.0d", -579103);
	assert_fmt("%-8.0d", -579103);
}

Test(d_tests, l_null_little_precision)
{
	assert_fmt("%-.2d", -579103);
	assert_fmt("%-0.2d", -579103);
	assert_fmt("%-2.2d", -579103);
	assert_fmt("%-6.2d", -579103);
	assert_fmt("%-8.2d", -579103);
}

Test(d_tests, l_null_right_precision)
{
	assert_fmt("%-.6d", -579103);
	assert_fmt("%-0.6d", -579103);
	assert_fmt("%-2.6d", -579103);
	assert_fmt("%-6.6d", -579103);
	assert_fmt("%-8.6d", -579103);
}

Test(d_tests, l_null_large_precision)
{
	assert_fmt("%-.8d", -579103);
	assert_fmt("%-0.8d", -579103);
	assert_fmt("%-2.8d", -579103);
	assert_fmt("%-6.8d", -579103);
	assert_fmt("%-8.8d", -579103);
}

//zero
Test(d_tests, l_empty_no_precision)
{
	assert_fmt("%-d", 0);
	assert_fmt("%-0d", 0);
	assert_fmt("%-2d", 0);
	assert_fmt("%0-2d", 0);
}

Test(d_tests, l_empty_zero_precision)
{
	assert_fmt("%-.0d", 0);
	assert_fmt("%0-.0d", 0);
	assert_fmt("%-0.0d", 0);
	assert_fmt("%0-0.0d", 0);
	assert_fmt("%-2.0d", 0);
	assert_fmt("%0-2.0d", 0);
}

Test(d_tests, l_empty_little_precision)
{
	assert_fmt("%-.2d", 0);
	assert_fmt("%0-.2d", 0);
	assert_fmt("%-0.2d", 0);
	assert_fmt("%0-0.2d", 0);
	assert_fmt("%-2.2d", 0);
	assert_fmt("%0-2.2d", 0);
}

//positive
Test(d_tests, l_string_no_precision)
{
	assert_fmt("%-d", 134578);
	assert_fmt("%-0d", 134578);
	assert_fmt("%-2d", 134578);
	assert_fmt("%-6d", 134578);
	assert_fmt("%-8d", 134578);
}

Test(d_tests, l_string_zero_precision)
{
	assert_fmt("%-.0d", 134578);
	assert_fmt("%-0.0d", 134578);
	assert_fmt("%-2.0d", 134578);
	assert_fmt("%-6.0d", 134578);
	assert_fmt("%-8.0d", 134578);
}

Test(d_tests, l_string_zero_precisoin)
{
	assert_fmt("%-.2d", 134578);
	assert_fmt("%-0.2d", 134578);
	assert_fmt("%-2.2d", 134578);
	assert_fmt("%-6.2d", 134578);
	assert_fmt("%-8.2d", 134578);
}

Test(d_tests, l_string_right_precision)
{
	assert_fmt("%-.6d", 134578);
	assert_fmt("%-0.6d", 134578);
	assert_fmt("%-2.6d", 134578);
	assert_fmt("%-6.6d", 134578);
	assert_fmt("%-8.6d", 134578);
}

Test(d_tests, l_string_large_precision)
{
	assert_fmt("%-.8d", 134578);
	assert_fmt("%-0.8d", 134578);
	assert_fmt("%-2.8d", 134578);
	assert_fmt("%-6.8d", 134578);
	assert_fmt("%-8.8d", 134578);
}

//right
	//negative
		//no width
			//no precision
			//zero precision
			//little precision
			//right precision
			//large precision
		//zero width
		//little width
		//right width
		//large width
	//zero
	//positive
//left
