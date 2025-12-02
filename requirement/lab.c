#include <stdio.h>

int	main(int ac, char **av) {
	(void)ac;
	(void)av;
	if (ac != 2)
		return (0);
	int	ret = printf(av[1], -3407);
	printf("\n\nreturn value was %d\n", ret);
	return (0);
}
