/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:03:57 by lea               #+#    #+#             */
/*   Updated: 2022/11/11 18:38:51 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_mutex_init(&(data->mutex.first_blood_mutex), NULL);
	pthread_mutex_init(&(data->mutex.is_everyone_alive_mutex), NULL);
	pthread_mutex_init(&(data->mutex.is_everyone_hungry_mutex), NULL);
}
