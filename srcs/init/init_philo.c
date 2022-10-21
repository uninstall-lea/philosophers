/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:51:31 by lea               #+#    #+#             */
/*   Updated: 2022/10/21 23:06:49 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(int i)
{
	t_data	*data;
	t_philo	*philo;
	
	data = _data();
	philo = _philo(i);
	if (!philo)
		printf("la loose\n");
	philo->num = i + 1;
	philo->nb_meal = 1;
	philo->finished = FALSE;
	philo->time_of_last_meal = 0;
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
