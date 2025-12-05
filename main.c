#include <limits.h>
#include <stddef.h>
//#include "bigass_string.h"
#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	int		ret;
	char	s[] = "hello";

    ret = ft_printf("%c and %s and %d\n", s[0], &s[0], s);
	printf("\n\nreturn value is %d\n", ret);
	return (0);
}
