/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:02:07 by lea               #+#    #+#             */
/*   Updated: 2022/10/21 23:14:06 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	pthread_create_philo(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	if (!data->philo)
		printf("la loose2\n");
	while (i < data->nb_philo)
	{
		printf("%d\n", i);
		init_philo(i);
		philo = _philo(i);
		if (pthread_create(&(philo->id), NULL, &philo_routine, philo)) // on protège
		{
			printf("Pthread_create failed\n");
			while (i--)
				pthread_join(philo->id, NULL);
			return (FAILURE);
		}
		i++;
	}
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
