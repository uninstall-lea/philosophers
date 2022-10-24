/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/25 00:55:53 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (time_since_last_meal(philo) > data->time_to_die)
	{
		pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
		data->is_everyone_alive = FALSE;
		pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
	}
}

void	check_usleep_death(int sleep, t_philo *philo)
{
	while (sleep > 0 && is_everyone_alive() == TRUE)
	{
		usleep(500);
		sleep -= 500;
		check_death(philo);
	}
}

int	everyone_alive_and_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	check_death(philo);
	if (is_everyone_alive() == TRUE && philo->nb_meal <= data->nb_meal_max)
		return (TRUE);
	else
	{
		print_death(philo);
		return (FALSE);
	}
}
