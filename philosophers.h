
#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_philo {
	int					id;
	long int			nb_eat;
	long int			last_eat;
	pthread_t			t_id;
	pthread_mutex_t    *forks_r;
	pthread_mutex_t    forks_l;
}               t_philo;

typedef struct s_info {

    int					die;
	int					nb_philo;
	size_t			time_start;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		eat_lock;

}           t_info;

int main(int argc, char **argv);
int check_arg(int ac, char **argv);
//void    thread_routine(void *data);
int     init_info(char **argv, char argc, t_info *info, t_philo *philo);
void    init_all(char **argv, int argc, t_philo *philo, t_info *info);
void *routine_philo(void *data);
int    init_thread(t_info *info, t_philo *philo);
int	ft_usleep(long time);
long	get_current_time(void);
t_info	*get_info(void);

#endif