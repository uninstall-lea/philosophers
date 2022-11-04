/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:42:55 by lea               #+#    #+#             */
/*   Updated: 2022/11/04 22:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->num % 2 == ODD)
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo->num, "has taken a fork");
		philo->have_left_fork = TRUE;
		pthread_mutex_lock(philo->right_fork);
		print(philo->num, "has taken a fork");
		philo->have_right_fork = TRUE;

	}
	else if (philo->num % 2 == EVEN)
	{
		pthread_mutex_lock(philo->right_fork);
		print(philo->num, "has taken a fork");
		philo->have_right_fork = TRUE;
		pthread_mutex_lock(philo->left_fork);
		print(philo->num, "has taken a fork");
		philo->have_left_fork = TRUE;
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->have_left_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		philo->have_left_fork = FALSE;
	}
	if (philo->have_right_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		philo->have_right_fork = FALSE;
	}
}

void free_all_data(void)
{
	t_data	*data;

	data = _data();
	free(data->philo);
	free(data->mutex.fork);
}
