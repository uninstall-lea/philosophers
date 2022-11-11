/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/11/11 18:46:07 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_thinking(t_philo *philo)
{
	print(philo, "is thinking");
	usleep(2000);
}

void	philo_eating(t_philo *philo)
{
	t_data	*data;

	data = _data();
	take_forks(philo);
	print(philo, EATING_MSG);
	pthread_mutex_lock(&(data->mutex.is_everyone_hungry_mutex));
	philo->nb_meal++;
	pthread_mutex_unlock(&(data->mutex.is_everyone_hungry_mutex));
	philo->time_of_last_meal = get_timestamp();
	check_usleep_death(data->time_to_eat, philo);
	drop_forks(philo);
}

void	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	print(philo, "is sleeping");
	check_usleep_death(data->time_to_sleep, philo);
}

void	*philo_routine(void *philo_ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = _data();
	philo = philo_ptr;
	if (data->nb_philo == 1)
		routine_for_lonely_philo(philo);
	while (everyone_alive_and_hungry(philo))
	{
		philo_thinking(philo);
		if (everyone_alive_and_hungry(philo))
			philo_eating(philo);
		if (everyone_alive_and_hungry(philo))
			philo_sleeping(philo);
	}
	drop_forks(philo);
	return (NULL);
}

void	routine_for_lonely_philo(t_philo *philo)
{
	t_data	*data;

	data = _data();
	philo_thinking(philo);
	pthread_mutex_lock(&(data->mutex.fork[0]));
	print(philo, "has taken a fork");
	usleep(data->time_to_die * 1000);
	pthread_mutex_unlock(&(data->mutex.fork[0]));
}
