/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:25 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/06/02 17:38:42 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_ready(t_data *data)
{
	int	ready;

	pthread_mutex_lock(&data->state_mutex);
	ready = data->ready;
	pthread_mutex_unlock(&data->state_mutex);
	return (ready);
}

void	wait_start(t_data *data)
{
	while (!simulation_ready(data))
		usleep(100);
}

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
