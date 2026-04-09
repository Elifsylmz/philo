#include "philo.h"

int parse_args(t_data *data, int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        printf("Usage: ./philo nb time_to_die time_to_eat time_to_sleep [must_eat]\n");
        return (0);
    }

    data->nb_philos     = ft_atoi(argv[1]);
    data->time_to_die   = ft_atoi(argv[2]);
    data->time_to_eat   = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);

    if (argc == 6)
        data->must_eat = ft_atoi(argv[5]);
    else
        data->must_eat = -1;

    if(data->nb_philos < 1 || data->time_to_die < 1
        || data->time_to_eat < 1 || data->time_to_sleep < 1
        || (argc == 6 && data->must_eat < 1))
    {
        printf("Error: all arguments must be positive integers\n");
        return(0);
    }

    return (1);
}