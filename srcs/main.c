/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:58 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 01:42:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_join_philo();
	free_all_data();
	return (0);
}
