/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/10/25 02:12:42 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	philo_thinking(t_philo *philo)
{
	print(philo->num, "is thinking");
}

void	philo_eating(t_philo *philo)
{
	t_data	*data;

	data = _data();
	take_forks(philo);
	print(philo->num, "is eating");
	philo->nb_meal++;
	philo->time_of_last_meal = get_timestamp();
	check_usleep_death(data->time_to_eat * 1000, philo);
	drop_forks(philo);
}

void	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = _data();
	print(philo->num, "is sleeping");
	check_usleep_death(data->time_to_sleep * 1000, philo);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;
	
	philo = philo_ptr;
//	printf("num : %d starts routine\n", philo->num);
	while (everyone_alive_and_hungry(philo))
	{
		philo_thinking(philo);
		if (everyone_alive_and_hungry(philo))
			philo_eating(philo);
		if (everyone_alive_and_hungry(philo))
			philo_sleeping(philo);
	}
	drop_forks(philo);
//	printf("num : %d has ended routine\n", philo->num);
	return (NULL);
}
