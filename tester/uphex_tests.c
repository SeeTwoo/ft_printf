#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

void	assert_fmt(char const *fmt, ...);

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
	assert_fmt("%+ X", 235796);
	assert_fmt("% +X", 235796);

	assert_fmt("%#X", 0x42);
	assert_fmt("%#X", 0);
	assert_fmt("%#X", LONG_MIN);
	assert_fmt("%#X", 0x123);
	assert_fmt("%+#X", 0x123);

	assert_fmt("%#.0X", 0);
	assert_fmt("%#.1X", 0);
	assert_fmt("%#.8X", 0x42);
	assert_fmt("%#.30X", 0x123);
	assert_fmt("%#10.0", 0);
	assert_fmt("%#0.0", 0);
	
	assert_fmt("%#10X", 0x42);
	assert_fmt("%#10X", 0x123);
	assert_fmt("%#20X", 0x42);

	assert_fmt("%#-10X", 0x42);
	assert_fmt("%#020X", 0x42);
	assert_fmt("%#08X", 0x42);
}
