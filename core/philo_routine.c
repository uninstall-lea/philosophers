/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/10/14 20:00:11 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	get_timestamp(void)
{
	int			timestamp;
	t_data		*data;
	t_timeval	current_time;
	
	data = _data();
	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec - data->start_time.tv_sec) * 1000
				+ (current_time.tv_usec - data->start_time.tv_usec) / 1000;
	return (timestamp);
}

void	philo_thinking(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf("%d %d is thinking\n", get_timestamp(), philo->num);
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
}

void	philo_eating(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
	printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
	printf("%d %d is eating\n", get_timestamp(), philo->num);
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	usleep(data->time_to_die);
}

void	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf("%d %d is sleeping\n", get_timestamp(), philo->num);
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	usleep(data->time_to_sleep);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;
	
	philo = philo_ptr;
	while (everyone_alive_and_hungry(philo) == TRUE)
	{
		philo_thinking(philo);
		philo_eating(philo);
		philo_sleeping(philo);
	}
	return (NULL);
}
