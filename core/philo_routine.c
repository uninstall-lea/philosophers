/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/10/11 18:29:12 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	get_timestamp(void)
{
	int				timestamp;
	t_data			*data;
	struct timeval	current_time;
	
	data = _data();
	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec - data->start_time.tv_sec) * 1000 
    		+ (current_time.tv_usec - data->start_time.tv_usec) / 1000;
	return (timestamp);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;
	int		timestamp;

	philo = philo_ptr;
	while (everyone_alive_and_hungry(philo) == TRUE)
	{
		timestamp = get_timestamp();
		printf("%d %d is thinking\n", timestamp, philo->num);
//		pthread_mutex_lock(philo->left_fork);
		printf("%d %d has taken a fork\n", timestamp, philo->num);
//		pthread_mutex_lock(philo->right_fork);
		printf("%d %d has taken a fork\n", timestamp, philo->num);
		printf("%d %d is eating\n", timestamp, philo->num);
//		pthread_mutex_unlock(philo->left_fork);
//		pthread_mutex_unlock(philo->right_fork);
		printf("%d %d is sleeping\n", timestamp, philo->num);
	}
	return (NULL);
}

// timestamp = (curent_time.tv_sec - start_time.sec) * 1000 
//           + (current_time.tv_usec - start_time.usec) / 1000
