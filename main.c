#include <limits.h>
#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	int	ret;

	ret = ft_printf("%X", 10);
	printf("\n\nreturn value is %d\n", ret);
	return (0);
}
