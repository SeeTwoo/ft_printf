#include <limits.h>
#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	ft_printf("%d", INT_MIN);
	return (0);
}
