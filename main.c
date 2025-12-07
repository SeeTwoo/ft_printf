#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	ft_printf(char const *format, ...);

int	main(void) {
	int		ret;
	char	large[1026];
	char	just_under[254];
	char	s[] = "hello";

	(void)s;
	memset(large, 'a', 1025);
	large[1025] = '\0';
	memset(just_under, 'a', 253);
	just_under[253] = '\0';

	ret = ft_printf("%s%s", just_under, large);
	printf("\n\nreturn value is %d\n", ret);
	return (0);
}
