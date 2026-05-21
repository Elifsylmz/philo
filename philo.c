#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philos;

	if (!parse_args(&data, argc, argv))
		return (1);
	if (!init_all(&philos, &data))
		return (1);
	if (!start_threads(&data, philos))
	{
		printf("Error: Thread creation failed\n");
		destroy_forks(&data, data.nb_philos);
		pthread_mutex_destroy(&data.print_mutex);
		pthread_mutex_destroy(&data.state_mutex);
		free(philos);
		return (1);
	}
	monitor_routine(&data, philos);
	join_threads(&data, philos);
	destroy_forks(&data, data.nb_philos);
	pthread_mutex_destroy(&data.print_mutex);
	pthread_mutex_destroy(&data.state_mutex);
	free(philos);
	return (0);
}
