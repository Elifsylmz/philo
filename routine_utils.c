#include "philo.h"

int	simulation_stopped(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->state_mutex);
	stopped = data->dead;
	pthread_mutex_unlock(&data->state_mutex);
	return (stopped);
}

void	smart_sleep(t_data *data, long ms)
{
	long	start;

	start = get_time();
	while (!simulation_stopped(data) && get_time() - start < ms)
		usleep(100);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
	if (philo->data->nb_philos % 2 == 1)
		smart_sleep(philo->data, philo->data->time_to_eat / 2);
}
