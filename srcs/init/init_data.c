/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:50:24 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 00:07:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data_div(int ac, char **av)
{
	t_data	*data;

	data = _data();
	data->nb_philo = ft_atoi(av[1]);
	if (ac == 6)
		data->nb_meal_max = ft_atoi(av[5]);
	else
		data->nb_meal_max = INT_MAX;
	data->is_everyone_alive = TRUE;
	gettimeofday(&(data->start_time), NULL);
}

void	init_data_time_to(char **av)
{
	t_data	*data;

	data = _data();
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
}

int	init_data(int ac, char **av)
{
	t_data	*data;

	data = _data();
	init_data_div(ac, av);
	init_data_time_to(av);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->mutex.fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->philo || !data->mutex.fork)
	{
		printf("Memory allocation failed\n");
		return (FAILURE);
	}
	init_philo();
	init_mutex();
	return (SUCCESS);
}
