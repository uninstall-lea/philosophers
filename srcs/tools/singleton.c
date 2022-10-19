/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:01 by lea               #+#    #+#             */
/*   Updated: 2022/10/17 18:22:49 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*_data(void)
{
	static t_data	data;
	static int		init = YES;

	if (init == YES)
	{
		init = NO;
		memset(&data, 0, sizeof(t_data));
	}
	return (&data);
}

t_philo *_philo(int i)
{
	t_data	*data;
	t_philo	*philo;

	data = _data();
	philo = &(data->philo[i]);
	return (philo);
}
