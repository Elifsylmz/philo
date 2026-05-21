/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:14 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/05/21 14:30:14 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->state_mutex);
	if (!philo->data->stop)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d %s\n", get_timestamp(philo->data), philo->id, status);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->state_mutex);
}

static int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->nb_philos == 1)
	{
		sleep_until_stop(philo->data, philo->data->time_to_die + 1);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	return (1);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_eat(t_philo *philo)
{
	if (!take_forks(philo))
		return ;
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->state_mutex);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->state_mutex);
	sleep_until_stop(philo->data, philo->data->time_to_eat);
	drop_forks(philo);
}

void	philo_sleep_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_until_stop(philo->data, philo->data->time_to_sleep);
	print_status(philo, "is thinking");
	if (philo->data->nb_philos % 2 == 1)
		sleep_until_stop(philo->data, philo->data->time_to_eat / 2);
}
