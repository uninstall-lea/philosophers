/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:57:59 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 00:49:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* conversion en miliseconds */
int	get_timestamp(void)
{
	int			timestamp;
	t_data		*data;
	t_timeval	current_time;

	data = _data();
	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec - data->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - data->start_time.tv_usec) / 1000;
	return (timestamp);
}

int	time_since_last_meal(t_philo *philo)
{
	int	current_time;

	current_time = get_timestamp();
	return (current_time - philo->time_of_last_meal);
}
