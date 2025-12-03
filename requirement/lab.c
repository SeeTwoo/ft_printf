#include <stdio.h>

int	main(int ac, char **av) {
	(void)ac;
	(void)av;
	if (ac != 2)
		return (0);
	int	ret = printf("% p", av);
	printf("\n\nreturn value was %d\n", ret);
	return (0);
}
