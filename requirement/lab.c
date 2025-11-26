#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	uintptr_t	n = UINT64_MAX;
	int			i = 0;

	printf("%llu\n", n);
	while (n > 16) {
		i++;
		n /= 16;
	}
	i++;
	printf("uintptr_t max len = %d\n", i);
	return (0);
}
