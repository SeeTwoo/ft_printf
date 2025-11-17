#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(int ac, char **av) {
	if (ac != 3)
		return (1);
	printf(av[1], av[2]);
	return (0);
}
