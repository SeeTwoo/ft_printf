#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	ft_printf("%030.10d\n", 234567);
	return (0);
}
