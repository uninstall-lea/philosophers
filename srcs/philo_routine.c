/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/10/17 18:50:58 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	philo_thinking(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	print(philo->num, "is thinking");
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
}

void	philo_eating(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	take_forks(philo);
	print(philo->num, "is eating");
	philo->nb_meal++;
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	gettimeofday(&philo->time_since_last_meal, NULL);
	usleep(data->time_to_eat * 1000);
}

void	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	print(philo->num, "is sleeping");
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	usleep(data->time_to_sleep * 1000);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;
	
	philo = philo_ptr;
	while (everyone_alive_and_hungry(philo))
	{
		philo_thinking(philo);
		if (everyone_alive_and_hungry(philo))
			philo_eating(philo);
		if (everyone_alive_and_hungry(philo))
			philo_sleeping(philo);
	}
	return (NULL);
}
