/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:42:55 by lea               #+#    #+#             */
/*   Updated: 2022/10/25 01:20:58 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_everyone_alive(void)
{
	int		tmp;
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
	tmp = data->is_everyone_alive;
	pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
	return (tmp);
}

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
		philo->left_fork = FALSE;
	}
	if (philo->have_right_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		philo->right_fork = FALSE;
	}
}

void free_all_data(void)
{
	t_data	*data;

	data = _data();
	free(data->philo);
	free(data->mutex.fork);
}
