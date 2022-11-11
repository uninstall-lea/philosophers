/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:58 by lea               #+#    #+#             */
/*   Updated: 2022/11/11 18:57:32 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	watcher(void)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	data = _data();
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			philo = _philo(i);
			if (everyone_alive_and_hungry(philo) == FALSE)
				return ;
			i++;
		}
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	if (!check_args(ac, av))
		return (FAILURE);
	if (!init_data(ac, av))
		return (FAILURE);
	if (!pthread_create_philo())
	{
		free_all_data();
		return (FAILURE);
	}
	watcher();
	pthread_join_philo();
	print_death();
	free_all_data();
	return (0);
}
