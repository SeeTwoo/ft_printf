#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	printf("[%0-45f]\n", 21.246456345);
	return (0);
}
