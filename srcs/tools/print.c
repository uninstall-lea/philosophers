/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:55:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/25 00:07:05 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int num, char *string)
{
	t_data	*data;
	
	data = _data();
	pthread_mutex_lock(&(data->mutex.baton_de_parole));
	printf("%d %d %s\n", get_timestamp(), num, string);
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
		pthread_mutex_lock(&(data->mutex.baton_de_parole));
		printf("%d %d died\n", get_timestamp(), philo->num);
	}
	pthread_mutex_unlock(&(data->mutex.first_blood_mutex));
}
