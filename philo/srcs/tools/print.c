/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:55:20 by lea               #+#    #+#             */
/*   Updated: 2022/11/06 01:54:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *msg)
{
	t_data	*data;

	data = _data();
	if (everyone_alive_and_hungry(philo) == FALSE)
		return ;
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf(BOLDYELLOW "%d " RESET "%d %s\n", get_timestamp(), philo->num, msg);
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
}

void	print_death(void)
{
	t_data		*data;

	data = _data();
	if (data->num_philo_who_died != 0)
		printf(BOLDYELLOW "%d " RESET "%d %s ☠️\n",
			get_timestamp(), data->num_philo_who_died, DEATH_MSG);
}
