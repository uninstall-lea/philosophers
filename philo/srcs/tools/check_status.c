/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/11/11 18:43:24 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*Prend en compte le décalage de usleep() */
void	check_usleep_death(int sleep, t_philo *philo)
{
	int	start_time;
	int	end_time;
	int	current_time;

	start_time = get_timestamp();
	end_time = start_time + sleep;
	current_time = start_time;
	while (current_time < end_time && is_everyone_alive(philo) == TRUE)
	{	
		usleep(500);
		current_time = get_timestamp();
	}
}

int	is_everyone_alive(t_philo *philo)
{
	int			tmp;
	t_data		*data;
	static int	first_blood = YES;

	data = _data();
	pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
	if (time_since_last_meal(philo) > data->time_to_die && first_blood == YES)
	{
		first_blood = NO;
		data->is_everyone_alive = FALSE;
		data->num_philo_who_died = philo->num;
	}
	tmp = data->is_everyone_alive;
	pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
	return (tmp);
}

int	is_everyone_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.is_everyone_hungry_mutex));
	if (philo->nb_meal <= data->nb_meal_max)
	{
		pthread_mutex_unlock(&(data->mutex.is_everyone_hungry_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(data->mutex.is_everyone_hungry_mutex));
	return (FALSE);
}

int	everyone_alive_and_hungry(t_philo *philo)
{
	if (is_everyone_alive(philo) == TRUE && is_everyone_hungry(philo) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
