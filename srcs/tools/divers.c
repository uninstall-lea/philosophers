/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:42:55 by lea               #+#    #+#             */
/*   Updated: 2022/10/17 18:22:46 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	take_forks(t_philo *philo)
{
	if (philo->num % 2 == ODD)
	{
		pthread_mutex_lock(&philo->left_fork);
		print(philo->num, "has taken a fork");
		pthread_mutex_unlock(&philo->left_fork);

	}
	else if (philo->num % 2 == EVEN)
	{
		pthread_mutex_lock(&philo->right_fork);
		print(philo->num, "has taken a fork");
		pthread_mutex_unlock(&philo->right_fork);
	}
}

void free_all_data(void)
{
	t_data	*data;

	data = _data();
	free(data->philo);
	free(data->mutex.fork);
}

void	print(int num, char *string)
{
	printf("%d %d %s\n", get_timestamp(), num, string);
}
