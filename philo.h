/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:30:22 by eyilmaz           #+#    #+#             */
/*   Updated: 2026/06/02 17:38:08 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	long			start_time;
	int				stop;
	int				ready;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

int					ft_atoi(const char *str);
long				get_time(void);
long				get_timestamp(t_data *data);
void				sleep_ms(long ms);
void				stop_simulation(t_data *data);
int					simulation_stopped(t_data *data);
void				sleep_until_stop(t_data *data, long ms);
void				wait_start(t_data *data);
int					simulation_ready(t_data *data);

int					ft_is_nb(const char *str);
int					check_args(int argc, char **argv);
int					parse_args(t_data *data, int argc, char **argv);

void				destroy_forks(t_data *data, int count);
int					init_forks(t_data *data);
int					init_philos(t_philo *philos, t_data *data);
int					init_all(t_philo **philos, t_data *data);

void				print_status(t_philo *philo, char *status);
void				philo_eat(t_philo *philo);
void				philo_sleep_think(t_philo *philo);
void				*philo_routine(void *arg);
int					start_threads(t_data *data, t_philo *philos);
void				join_threads(t_data *data, t_philo *philos);

void				monitor_routine(t_data *data, t_philo *philos);

#endif