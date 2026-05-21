#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		smart_sleep(philo->data, philo->data->time_to_eat / 2);
	while (!simulation_stopped(philo->data))
	{
		philo_eat(philo);
		if (simulation_stopped(philo->data))
			break ;
		philo_sleep_think(philo);
	}
	return (NULL);
}

int	start_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philos)
	{
		philos[i].last_meal = data->start_time;
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
