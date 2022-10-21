/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:58 by lea               #+#    #+#             */
/*   Updated: 2022/10/22 00:34:46 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data *data;

	data = _data();
	if (!check_args(ac, av))
		return (FAILURE);
	if (!init_data(ac, av))
		return (FAILURE);
//	if (!data->philo)
//		printf("allo3\n");
	if (!pthread_create_philo())
		return (FAILURE);
	pthread_join_philo();
	free_all_data();
	return (0);
}
