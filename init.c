#include "philosophers.h"


/*int init_fork(t_info *info , t_philo *philo)
{
    int i = 0;

    while (i < info->nb_philo)
    {
        pthread_mutex_init(philo->forks[i], NULL)
    }
}*/

int init_mutex(t_info *info, t_philo *philo)
{
    int i;

    i = 1;
    while (i <= info->nb_philo)
    {
        if (pthread_mutex_init(&philo[i].forks_l, NULL))
            return (-1);
        if (pthread_mutex_init(philo[i].forks_r, NULL))
            return (-1);
        i++;
    }
}

int    init_thread(t_info *info, t_philo *philo)
{
    int i;

    i = 1;
    printf("i = %d\n [[%ld]]nb philo = %d\n }} ", i,philo[i].t_id , info->nb_philo);
    while (i <= info->nb_philo)
    {
       
       	pthread_create(&philo[i].t_id, NULL, routine_philo, &philo[i]);
        pthread_join(philo[i].t_id, NULL);
       
        i++;
    }
}

int     init_info(char **argv, char argc, t_info *info, t_philo *philo)
{
    int i ;

    i = 1;

    info->nb_philo = atoi(argv[1]);
    info->time_die = atoi(argv[2]);
    info->time_eat = atoi(argv[3]);
    info->time_sleep = atoi(argv[4]);
    info->die = 0;
    info->fork = malloc(sizeof(int) * info->nb_philo);

    while (i <= info->nb_philo)
    {
        philo[i].id = i;
        philo[i].forks_r = &philo[(i + 1) % info->nb_philo].forks_l;
        i++;
    }
   return 1;
}

void    init_all(char **argv, int argc, t_philo *philo, t_info *info)
{
    init_info(argv, argc, info, philo);
    printf("philo : %d t_die :%d t_eat : %d t_sleep : %d \n", info->nb_philo, info->time_die, info->time_eat, info->time_sleep);
    init_mutex(info, philo);
    init_thread(info, philo);
    return ;
}