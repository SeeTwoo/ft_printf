#include <limits.h>
#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	int	ret;
	ret = ft_printf("%s", NULL);
	printf("\n\nreturn value is %d\n", ret);

	::printf("%s\n", NULL);
	::printf("%.10s", NULL);
	::printf("%.2s", NULL);
	return (0);
}
