#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->state_mutex);
	if (!philo->data->dead)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, status);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	
	if (philo->data->nb_philos == 1)
	{
		ft_usleep(philo->data->time_to_die + 1);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}

	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");

	print_status(philo, "is eating");
	
	pthread_mutex_lock(&philo->data->state_mutex);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->state_mutex);

	ft_usleep(philo->data->time_to_eat);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		pthread_mutex_lock(&philo->data->state_mutex);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->state_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->data->state_mutex);

		philo_eat(philo);
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
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
		if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) != 0)
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