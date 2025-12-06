#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>

void	assert_fmt(char const *fmt, ...);


Test(s_tests, mandatory_strings)
{
	char	wee[] = "hello";
	char	mid[] = "hey this is 8";
	char	huger[] = "hey this is a long one to go fur multiple words inside of the swar strlen";

    assert_fmt("%s", NULL);
    assert_fmt("%s", "");
    assert_fmt("%s", "hello, world !");
	assert_fmt("%s", wee);
	assert_fmt("%s", mid);
	assert_fmt("%s", huger);
}

//large
Test(s_tests, large_output)
{
	char	large[1026];
	char	just_under[254];
	char	s[] = "hello";

	memset(large, 'a', 1025);
	large[1025] = '\0';
	memset(just_under, 'a', 253);
	just_under[253] = '\0';
	assert_fmt("%s", large);
	assert_fmt("%s%s", just_under, s);
}

//star
Test(s_tests, stars)
{
	char	wee[] = "hello";

	assert_fmt("%*s", 30, wee);
	assert_fmt("%*s", -30, wee);
	assert_fmt("%.*s", 30, wee);
	assert_fmt("%.*s", -30, wee);
}

//NULL
Test(s_tests, null_no_precision)
{
	assert_fmt("%s", NULL);
	assert_fmt("%0s", NULL);
	assert_fmt("%2s", NULL);
	assert_fmt("%6s", NULL);
	assert_fmt("%8s", NULL);
}

Test(s_tests, null_zero_precision)
{
	assert_fmt("%.0s", NULL);
	assert_fmt("%0.0s", NULL);
	assert_fmt("%2.0s", NULL);
	assert_fmt("%6.0s", NULL);
	assert_fmt("%8.0s", NULL);
}

Test(s_tests, null_little_precision)
{
	assert_fmt("%.2s", NULL);
	assert_fmt("%0.2s", NULL);
	assert_fmt("%2.2s", NULL);
	assert_fmt("%6.2s", NULL);
	assert_fmt("%8.2s", NULL);
}

Test(s_tests, null_right_precision)
{
	assert_fmt("%.6s", NULL);
	assert_fmt("%0.6s", NULL);
	assert_fmt("%2.6s", NULL);
	assert_fmt("%6.6s", NULL);
	assert_fmt("%8.6s", NULL);
}

Test(s_tests, null_large_precision)
{
	assert_fmt("%.8s", NULL);
	assert_fmt("%0.8s", NULL);
	assert_fmt("%2.8s", NULL);
	assert_fmt("%6.8s", NULL);
	assert_fmt("%8.8s", NULL);
}

//emty string
Test(s_tests, empty_no_precision)
{
	assert_fmt("%s", "");
	assert_fmt("%0s", "");
	assert_fmt("%2s", "");
	assert_fmt("%6s", "");
	assert_fmt("%8s", "");
}

Test(s_tests, emtpy_zero_precision)
{
	assert_fmt("%.0s", "");
	assert_fmt("%0.0s", "");
	assert_fmt("%2.0s", "");
	assert_fmt("%6.0s", "");
	assert_fmt("%8.0s", "");
}

Test(s_tests, emtpy_little_precision)
{
	assert_fmt("%.2s", "");
	assert_fmt("%0.2s", "");
	assert_fmt("%2.2s", "");
	assert_fmt("%6.2s", "");
	assert_fmt("%8.2s", "");
}

Test(s_tests, emtpy_right_precision)
{
	assert_fmt("%.8s", "");
	assert_fmt("%0.6s", "");
	assert_fmt("%2.6s", "");
	assert_fmt("%6.6s", "");
	assert_fmt("%8.6s", "");
}

Test(s_tests, emtpy_large_precision)
{
	assert_fmt("%.8s", "");
	assert_fmt("%0.8s", "");
	assert_fmt("%2.8s", "");
	assert_fmt("%6.8s", "");
	assert_fmt("%8.8s", "");
}

//argument
Test(s_tests, string_no_precision)
{
	assert_fmt("%s", "hello");
	assert_fmt("%0s", "hello");
	assert_fmt("%2s", "hello");
	assert_fmt("%6s", "hello");
	assert_fmt("%8s", "hello");
}

Test(s_tests, string_zero_precision)
{
	assert_fmt("%.0s", "hello");
	assert_fmt("%0.0s", "hello");
	assert_fmt("%2.0s", "hello");
	assert_fmt("%6.0s", "hello");
	assert_fmt("%8.0s", "hello");
}

Test(s_tests, string_zero_precisoin)
{
	assert_fmt("%.2s", "hello");
	assert_fmt("%0.2s", "hello");
	assert_fmt("%2.2s", "hello");
	assert_fmt("%6.2s", "hello");
	assert_fmt("%8.2s", "hello");
}

Test(s_tests, string_right_precision)
{
	assert_fmt("%.6s", "hello");
	assert_fmt("%0.6s", "hello");
	assert_fmt("%2.6s", "hello");
	assert_fmt("%6.6s", "hello");
	assert_fmt("%8.6s", "hello");
}

Test(s_tests, string_large_precision)
{
	assert_fmt("%.8s", "hello");
	assert_fmt("%0.8s", "hello");
	assert_fmt("%2.8s", "hello");
	assert_fmt("%6.8s", "hello");
	assert_fmt("%8.8s", "hello");
}

//==========================================================
/////left justification
//==========================================================


//NULL
Test(s_tests, l_null_no_precision)
{
	assert_fmt("%-s", NULL);
	assert_fmt("%-0s", NULL);
	assert_fmt("%-2s", NULL);
	assert_fmt("%-6s", NULL);
	assert_fmt("%-8s", NULL);
}

Test(s_tests, l_null_zero_precision)
{
	assert_fmt("%-.0s", NULL);
	assert_fmt("%-0.0s", NULL);
	assert_fmt("%-2.0s", NULL);
	assert_fmt("%-6.0s", NULL);
	assert_fmt("%-8.0s", NULL);
}

Test(s_tests, l_null_little_precision)
{
	assert_fmt("%-.2s", NULL);
	assert_fmt("%-0.2s", NULL);
	assert_fmt("%-2.2s", NULL);
	assert_fmt("%-6.2s", NULL);
	assert_fmt("%-8.2s", NULL);
}

Test(s_tests, l_null_right_precision)
{
	assert_fmt("%-.6s", NULL);
	assert_fmt("%-0.6s", NULL);
	assert_fmt("%-2.6s", NULL);
	assert_fmt("%-6.6s", NULL);
	assert_fmt("%-8.6s", NULL);
}

Test(s_tests, l_null_large_precision)
{
	assert_fmt("%-.8s", NULL);
	assert_fmt("%-0.8s", NULL);
	assert_fmt("%-2.8s", NULL);
	assert_fmt("%-6.8s", NULL);
	assert_fmt("%-8.8s", NULL);
}

//emty string
Test(s_tests, l_empty_no_precision)
{
	assert_fmt("%-s", "");
	assert_fmt("%-0s", "");
	assert_fmt("%-2s", "");
	assert_fmt("%-6s", "");
	assert_fmt("%-8s", "");
}

Test(s_tests, l_empty_zero_precision)
{
	assert_fmt("%-.0s", "");
	assert_fmt("%-0.0s", "");
	assert_fmt("%-2.0s", "");
	assert_fmt("%-6.0s", "");
	assert_fmt("%-8.0s", "");
}

Test(s_tests, l_empty_little_precision)
{
	assert_fmt("%-.2s", "");
	assert_fmt("%-0.2s", "");
	assert_fmt("%-2.2s", "");
	assert_fmt("%-6.2s", "");
	assert_fmt("%-8.2s", "");
}

Test(s_tests, l_empty_right_precision)
{
	assert_fmt("%-.6s", "");
	assert_fmt("%-0.6s", "");
	assert_fmt("%-2.6s", "");
	assert_fmt("%-6.6s", "");
	assert_fmt("%-8.6s", "");
}

Test(s_tests, l_empty_large_precision)
{
	assert_fmt("%-.8s", "");
	assert_fmt("%-0.8s", "");
	assert_fmt("%-2.8s", "");
	assert_fmt("%-6.8s", "");
	assert_fmt("%-8.8s", "");
}

//argument
Test(s_tests, l_string_no_precision)
{
	assert_fmt("%-s", "hello");
	assert_fmt("%-0s", "hello");
	assert_fmt("%-2s", "hello");
	assert_fmt("%-6s", "hello");
	assert_fmt("%-8s", "hello");
}

Test(s_tests, l_string_zero_precision)
{
	assert_fmt("%-.0s", "hello");
	assert_fmt("%-0.0s", "hello");
	assert_fmt("%-2.0s", "hello");
	assert_fmt("%-6.0s", "hello");
	assert_fmt("%-8.0s", "hello");
}

Test(s_tests, l_string_zero_precisoin)
{
	assert_fmt("%-.2s", "hello");
	assert_fmt("%-0.2s", "hello");
	assert_fmt("%-2.2s", "hello");
	assert_fmt("%-6.2s", "hello");
	assert_fmt("%-8.2s", "hello");
}

Test(s_tests, l_string_right_precision)
{
	assert_fmt("%-.6s", "hello");
	assert_fmt("%-0.6s", "hello");
	assert_fmt("%-2.6s", "hello");
	assert_fmt("%-6.6s", "hello");
	assert_fmt("%-8.6s", "hello");
}

Test(s_tests, l_string_large_precision)
{
	assert_fmt("%-.8s", "hello");
	assert_fmt("%-0.8s", "hello");
	assert_fmt("%-2.8s", "hello");
	assert_fmt("%-6.8s", "hello");
	assert_fmt("%-8.8s", "hello");
}


//right
	//null
		// no precision
			// no width
			// 0 width
			// little width
			// right width
			// large width
		// 0 precision
		// to little precision
		// enough precision
		// large precision
	//emtpy
	//existing

//left
