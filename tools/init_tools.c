/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:03:57 by lea               #+#    #+#             */
/*   Updated: 2022/10/03 22:26:53 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_mutex(int i)
{
	t_philo	*philo;

	philo = _philo(i);
	pthread_mutex_init(philo->left_fork, NULL);
	pthread_mutex_init(philo->right_fork, NULL);
}

int	init_data(int ac, char **av)
{
	t_data	*data;
	
	data = _data();
	data->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!data->philo)
	{
		printf("Memory allocation failed\n");
		return (FAILURE);
	}
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal_max = ft_atoi(av[5]);
	else
		data->nb_meal_max = INT_MAX;
	data->is_everyone_alive = TRUE;
	return (SUCCESS);
}

void	init_philo(int i)
{
	t_philo	*philo;
	
	philo = _philo(i);
	//printf("i : %d\n", i);
	philo->num = i + 1;
	philo->nb_meal = 0;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->finished = FALSE;
	philo->time_since_last_meal = 0;
}
