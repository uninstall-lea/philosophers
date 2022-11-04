/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:55:20 by lea               #+#    #+#             */
/*   Updated: 2022/11/04 22:13:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int num, char *string)
{
	t_data	*data;
	t_philo	*philo;
	
	data = _data();
	philo = _philo(num - 1);
	if (everyone_alive_and_hungry(philo) == FALSE)
		return ;
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
//		usleep(3000);
		printf("%d %d died\n", get_timestamp(), philo->num);
		pthread_mutex_unlock(&(data->mutex.baton_de_parole));
	}
	pthread_mutex_unlock(&(data->mutex.first_blood_mutex));
}
