#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	printf("%d ",philo->id);
	printf("%s\n", str);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks_l);
	print(philo ,"Has taking a fork the left one");
	pthread_mutex_lock(philo->forks_r);
	print(philo ,"Has taking a fork the ritgh one");
}

void *routine_philo(void *data)
{
	t_info		*info;
	t_philo     *philo;
	
	philo = (t_philo *)data;
	printf("Philo %d\n", philo->id);
	take_fork(philo);
	pthread_mutex_unlock(&philo->forks_l);
	pthread_mutex_unlock(philo->forks_r);
	return (NULL); // Le thread termine ici.;
}