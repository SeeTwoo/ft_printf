#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	char	c = 'c';
	char	s[] = "hello world";
	int		i = 2934435;
	float	f = 234.453;

	int		pids[2];

	pids[0] = fork();
	if (pids[0] == 0) {
		printf("hello, here is a long message with a char : %c and a string : %s and an int : %d and a float : %f\n", c, s, i, f);
		exit(EXIT_SUCCESS);
	}
	pids[1] = fork();
	if (pids[1] == 0) {
		printf("hello, here is a long message with a char : %c and a string : %s and an int : %d and a float : %f\n", c, s, i, f);
		exit(EXIT_SUCCESS);
	}
	waitpid(pids[0], 0, 0);
	waitpid(pids[1], 0, 0);
	return (0);
}
