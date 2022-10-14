/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:58 by lea               #+#    #+#             */
/*   Updated: 2022/10/14 19:14:34 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int main(int ac, char **av)
{
	if (!check_args(ac, av))
		return (FAILURE);
	if (!init_data(ac, av))
		return (FAILURE);
	if (!pthread_create_philo())
		return (FAILURE);
	pthread_join_philo();
	return (SUCCESS);
}
