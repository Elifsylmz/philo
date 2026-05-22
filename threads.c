/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:27 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/05/21 14:30:28 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_created_threads(t_philo *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

static void	set_start_values(t_data *data, t_philo *philos)
{
	int		i;
	long	time;

	i = 0;
	time = get_time();
	pthread_mutex_lock(&data->state_mutex);
	data->start_time = time;
	while (i < data->nb_philos)
	{
		philos[i].last_meal = time;
		i++;
	}
	data->ready = 1;
	pthread_mutex_unlock(&data->state_mutex);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_start(philo->data);
	if (philo->id % 2 == 0)
		sleep_until_stop(philo->data, philo->data->time_to_eat / 2);
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
	while (i < data->nb_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine,
				&philos[i]) != 0)
		{
			stop_simulation(data);
			join_created_threads(philos, i);
			return (0);
		}
		i++;
	}
	set_start_values(data, philos);
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
