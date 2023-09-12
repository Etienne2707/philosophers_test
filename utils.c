#include "philosophers.h"

int	ft_usleep(long time)
{
	long	start;

	start = get_current_time();
	//printf("current time %d", get_current_time() - start);
	while (get_current_time() - start < time)
	{
		printf("current time %d", get_current_time() - start);
		usleep(10);
		printf("i");
	}
	printf("i");
	return (1);
}

// Gets the current time in time

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	//printf("%ld", time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
