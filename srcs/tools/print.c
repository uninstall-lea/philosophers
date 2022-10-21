/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:55:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/21 23:00:13 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int num, char *string)
{
	printf("%d %d %s\n", get_timestamp(), num, string);
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
		print(philo->num, "died");
		pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	}
	pthread_mutex_unlock(&(data->mutex.first_blood_mutex));
}
