#include <limits.h>
#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	ft_printf("%05d", 42);
	return (0);
}
