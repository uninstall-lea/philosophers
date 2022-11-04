/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/11/04 23:07:45 by marvin           ###   ########.fr       */
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
	print(philo, "is eating");
	philo->nb_meal++;
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
	drop_forks(philo);
	return (NULL);
}
