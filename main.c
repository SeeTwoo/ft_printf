#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	char	*s = NULL;

	ft_printf("%.5s\n", s);
	return (0);
}
