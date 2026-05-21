/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:30 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/05/21 14:30:30 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 214748364 || (result == 214748364 && (str[i] - '0') > 7))
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_sec * 1000 + (long)time.tv_usec / 1000);
}

long	get_timestamp(t_data *data)
{
	return (get_time() - data->start_time);
}

void	sleep_ms(long ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(100);
}
