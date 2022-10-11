/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:02:07 by lea               #+#    #+#             */
/*   Updated: 2022/10/03 22:27:10 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	create_philo(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		init_philo(i);
		philo = _philo(i);
		init_mutex(i);
		if (pthread_create(&philo[i].philo_id, NULL, &philo_routine, &philo[i])) // on protège
		{
			printf("Pthread_create failed\n");
			while (i--)
				pthread_join(philo[i].philo_id, NULL);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

void	join_philo(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		philo = _philo(i);
		pthread_join(philo[i].philo_id, NULL);
		i++;
	}
}
