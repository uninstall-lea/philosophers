/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:55:20 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 00:19:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *string)
{
	t_data	*data;

	data = _data();
	if (everyone_alive_and_hungry(philo) == FALSE)
		return ;
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf("%d %d %s\n", get_timestamp(), philo->num, string);
	pthread_mutex_unlock(&(data->mutex.baton_de_parole));
}

void	print_death(t_philo *philo)
{
	t_data		*data;
	static int	first_blood = YES;

	data = _data();
	pthread_mutex_lock(&(data->mutex.first_blood_mutex));
	if (first_blood == YES)
	{
		first_blood = NO;
		usleep(3000);
		pthread_mutex_lock(&(data->mutex.baton_de_parole));
		printf("%d %d died\n", get_timestamp(), philo->num);
		pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	}
	pthread_mutex_unlock(&(data->mutex.first_blood_mutex));
}
