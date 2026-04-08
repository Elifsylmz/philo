#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

typedef struct s_data
{
    int             nb_philos;
    long            time_to_die;
    long            time_to_eat;
    long            time_to_sleep;
    int             must_eat;       // bu verilmezse -1
    long            start_time;
    int             dead;
    int             all_ate;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t state_mutex;
}   t_data;

typedef struct s_philo
{
    int             id;
    int             eat_count;
    long            last_meal;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
}   t_philo;

int ft_atoi(const char *str);
long    get_time(void);

int parse_args(t_data *data, int argc, char **argv);

#endif