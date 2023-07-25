#include "philosophers.h"


int     init_info(char **argv, char argc, t_info *info)
{
    info->nb_philo = atoi(argv[1]);
    /*
    info->time_die = atoi(argv[2]);
    info->time_eat = atoi(argv[3]);
    info->time_sleep = atoi(argv[4]);
    info->die = 0;
    */
   return 1;
}

void    init_all(char **argv, int argc, t_philo *philo, t_info *info)
{
    init_info(argv, argc, info);
    printf("%d\n", info->nb_philo);
 
    return ;
}