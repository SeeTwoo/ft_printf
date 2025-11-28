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
	long	time;

	time = (start_time - get_time_ms()) / 2;
	while (get_time_ms() < start_time)
	{
		usleep(time);
		time = (start_time - get_time_ms()) / 2;
	}
}

int	main(void)
{
	char	a[2050];
	char	b[2050];

	memset(a, 'a', 2049);
	memset(b, 'b', 2049);
	a[2049] = '\0';
	b[2049] = '\0';
	int		pids[2];

	long	start_time = get_time_ms() + 3000;
	pids[0] = fork();
	if (pids[0] == 0) {
		wait_for_start(start_time);
		printf("%s%s%s%s\n", a, a, a, a);
		exit(EXIT_SUCCESS);
	}
	pids[1] = fork();
	if (pids[1] == 0) {
		wait_for_start(start_time);
		printf("%s%s%s%s\n", b, b, b, b);
		exit(EXIT_SUCCESS);
	}
	waitpid(pids[0], 0, 0);
	waitpid(pids[1], 0, 0);
	return (0);
}
