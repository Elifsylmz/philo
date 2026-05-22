/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:06 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/05/21 14:30:06 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_data *data, int count)
{
	while (count-- > 0)
		pthread_mutex_destroy(&data->forks[count]);
	free(data->forks);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (destroy_forks(data, i), 0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		destroy_forks(data, data->nb_philos);
		return (0);
	}
	if (pthread_mutex_init(&data->state_mutex, NULL) != 0)
	{
		destroy_forks(data, data->nb_philos);
		pthread_mutex_destroy(&data->print_mutex);
		return (0);
	}
	return (1);
}

int	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].data = data;
		if (i % 2 == 0)
		{
			philos[i].left_fork = &data->forks[(i + 1) % data->nb_philos];
			philos[i].right_fork = &data->forks[i];
		}
		else
		{
			philos[i].left_fork = &data->forks[i];
			philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		}
		i++;
	}
	return (1);
}

int	init_all(t_philo **philos, t_data *data)
{
	*philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!(*philos))
		return (0);
	if (!init_forks(data))
	{
		free(*philos);
		return (0);
	}
	data->stop = 0;
	data->ready = 0;
	if (!init_philos(*philos, data))
	{
		destroy_forks(data, data->nb_philos);
		free(*philos);
		return (0);
	}
	return (1);
}
