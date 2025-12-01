#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	wait_for_start(long start_time)
{
	while (get_time_ms() < start_time)
		usleep(2);
}

#define HD "bash : "
#define CMD_FND "command not found : "
#define WRONG "catte"

int	main(void)
{
	int		pids[2];

	long	start_time = get_time_ms() + 100;
	pids[0] = fork();
	if (pids[0] == 0) {
		wait_for_start(start_time);
		printf("%s%s%s\n", HD, CMD_FND, WRONG);
		exit(EXIT_SUCCESS);
	}
	pids[1] = fork();
	if (pids[1] == 0) {
		wait_for_start(start_time);
		printf("%s%s%s\n", HD, CMD_FND, WRONG);
		exit(EXIT_SUCCESS);
	}
	waitpid(pids[0], 0, 0);
	waitpid(pids[1], 0, 0);
	return (0);
}
