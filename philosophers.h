
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
	pthread_t			t_id;
}               t_philo;

typedef struct s_info {

    int					die;
	int					nb_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;

}           t_info;

int main(int argc, char **argv);
int check_arg(int ac, char **argv);
//void    thread_routine(void *data);
int     init_info(char **argv, char argc, t_info *info);
void    init_all(char **argv, int argc, t_philo *philo, t_info *info);


#endif