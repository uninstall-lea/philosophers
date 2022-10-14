/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:03:57 by lea               #+#    #+#             */
/*   Updated: 2022/10/14 19:47:56 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

void	init_mutex(void)
{
	int		i;
	t_data	*data;
	
	i = 0;
	data = _data();
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&(data->mutex.fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->mutex.baton_de_parole), NULL);
}

int	init_data(int ac, char **av)
{
	t_data	*data;
	
	data = _data();
	init_data_div(ac, av);
	init_data_time_to(av);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->mutex.fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (! data->philo || !data->mutex.fork)
	{
		printf("Memory allocation failed\n");
		return (FAILURE);
	}
	init_mutex();
	return (SUCCESS);
}


void	init_philo(int i)
{
	t_philo	*philo;
	
	philo = _philo(i);
	philo->num = i + 1;
	philo->nb_meal = 1;
	philo->finished = FALSE;
	philo->time_since_last_meal = 0;
}
