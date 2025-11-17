#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	char	s[] = "hello, world";

	ft_printf("%20s\n", s);
	return (0);
}
