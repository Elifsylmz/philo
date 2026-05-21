#include "philo.h"

int	simulation_stopped(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->state_mutex);
	stopped = data->stop;
	pthread_mutex_unlock(&data->state_mutex);
	return (stopped);
}

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->state_mutex);
}

void	sleep_until_stop(t_data *data, long ms)
{
	long	start;

	start = get_time();
	while (!simulation_stopped(data) && get_time() - start < ms)
		usleep(100);
}
