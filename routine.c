#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	t_info *info;
	size_t	t;
	info = get_info();

	
	pthread_mutex_lock(&info->print_lock);
	t = get_current_time() - info->time_start;
	printf("%ld  ", t);
	printf("%d ",philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(&info->print_lock);
}

void	think(t_philo *philo, t_info *info)
{
	print(philo, "Is thinking");
}

void	sleepfort(t_philo *philo)
{
	t_info *info;

	info = get_info();
	print(philo, "Is sleeping");
	ft_usleep(info->time_sleep);
}
	 
	

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks_l);
	print(philo ,"Has taking a fork ");
	pthread_mutex_lock(philo->forks_r);
	print(philo ,"Has taking a fork ");
}

void	eat(t_philo *philo)
{
	t_info *info;
	info = get_info();

	pthread_mutex_lock(&info->eat_lock);
	//philo->last_eat = get_current_time() - info->time_start;
	print(philo, "Is eating");
	pthread_mutex_unlock(&info->eat_lock);
	usleep(100);
	write(1, "test", 4);
	
}

void *routine_philo(void *data)
{
	t_info		*info;
	t_philo     *philo;
	
	int i = 20;
	philo = (t_philo *)data;
	info = get_info();
	while (i > 0)
	{
		take_fork(philo);
		eat(philo);
		pthread_mutex_unlock(&philo->forks_l);
		pthread_mutex_unlock(philo->forks_r);
		sleepfort(philo);
		think(philo, info);
		i--;
	}

	return (NULL); // Le thread termine ici.;
}