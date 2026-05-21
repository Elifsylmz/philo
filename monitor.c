#include "philo.h"

static int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->state_mutex);
	if (get_time() - philo->last_meal >= philo->data->time_to_die)
	{
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->state_mutex);
		
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d died\n", get_time() - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		
		return (1);
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
	return (0);
}

static int	check_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	if (philos[0].data->must_eat == -1)
		return (0);
	i = 0;
	finished_eating = 0;
	while (i < philos[0].data->nb_philos)
	{
		pthread_mutex_lock(&philos[0].data->state_mutex);
		if (philos[i].eat_count >= philos[0].data->must_eat)
			finished_eating++;
		pthread_mutex_unlock(&philos[0].data->state_mutex);
		i++;
	}
	if (finished_eating == philos[0].data->nb_philos)
	{
		pthread_mutex_lock(&philos[0].data->state_mutex);
		philos[0].data->stop = 1;
		pthread_mutex_unlock(&philos[0].data->state_mutex);
		return (1);
	}
	return (0);
}

void	monitor_routine(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (check_death(&philos[i]))
				return ;
			i++;
		}
		if (check_all_ate(philos))
			return ;
		ft_usleep(1); 
	}
}
