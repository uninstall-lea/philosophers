/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:31 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 00:06:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(int i, t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (i == 0)
	{
		philo->left_fork = &data->mutex.fork[i];
		philo->right_fork = &data->mutex.fork[data->nb_philo - 1];
	}
	else
	{
		philo->left_fork = &data->mutex.fork[i];
		philo->right_fork = &data->mutex.fork[i - 1];
	}
}

void	init_philo(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		philo->num = i + 1;
		philo->nb_meal = 1;
		philo->finished = FALSE;
		philo->have_left_fork = FALSE;
		philo->have_right_fork = FALSE;
		philo->time_of_last_meal = 0;
		init_forks(i, philo);
		i++;
	}
}
