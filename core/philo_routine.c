/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:04:51 by lea               #+#    #+#             */
/*   Updated: 2022/10/03 21:59:56 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_routine(void *philo_ptr)
{
//	t_data	*data;
	t_philo	*philo;
	int		timestamp;

//	data = _data();
	philo = philo_ptr;
//	get_timestamp(&timestamp);
	timestamp = 1;
	while (everyone_alive_and_hungry(philo) == TRUE)
	{
		printf("%d %d is thinking\n", timestamp, philo->num);
		pthread_mutex_lock(philo->left_fork);
		printf("%d %d has taken a fork\n", timestamp, philo->num);
		pthread_mutex_lock(philo->right_fork);
		printf("%d %d has taken a fork\n", timestamp, philo->num);
		printf("%d %d is eating\n", timestamp, philo->num);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("%d %d is sleeping\n", timestamp, philo->num);
		
		
//		printf("%d %d is thinking\n", timestamp, philo->num);
//		printf("%d %d is eating\n", timestamp, philo->num);
//		printf("%d %d is sleeping\n", timestamp, philo->num);
	}
	return (NULL);
}

// timestamp = (curent_time.tv_sec - start_time.sec) * 1000 
//           + (current_time.tv_usec - start_time.usec) / 1000
