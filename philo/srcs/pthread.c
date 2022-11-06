/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:02:07 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 17:42:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_even(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (i % 2 == EVEN)
		{
			if (pthread_create(&(philo->id), NULL, &philo_routine, philo))
			{
				printf("Pthread_create failed\n");
				pthread_join_philo();
				return (FAILURE);
			}
		}
		i++;
	}
	return (SUCCESS);
}

int	start_odd(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		if (i % 2 == ODD)
		{
			if (pthread_create(&(philo->id), NULL, &philo_routine, philo))
			{
				printf("Pthread_create failed\n");
				pthread_join_philo();
				return (FAILURE);
			}
		}
		i++;
	}
	return (SUCCESS);
}

int	pthread_create_philo(void)
{
	if (start_even() == FAILURE || start_odd() == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	pthread_join_philo(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		pthread_join(philo->id, NULL);
		i++;
	}
}
