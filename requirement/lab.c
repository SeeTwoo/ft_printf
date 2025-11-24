#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		n = 42;

	printf("[%#030.15p]\n", &n);
	return (0);
}
