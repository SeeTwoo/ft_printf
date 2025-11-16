#include <stddef.h>
#include "bigass_string.h"

int	ft_printf(char const *format, ...);

int	main(void) {
	ft_printf(BIGASS_STRING);
	ft_printf("hello world\n");
	ft_printf("");
	ft_printf(NULL);
	return (0);
}
