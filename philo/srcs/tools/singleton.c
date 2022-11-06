/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:01 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 00:19:07 by marvin           ###   ########.fr       */
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
		ft_bzero(&data, sizeof(t_data));
	}
	return (&data);
}

t_philo	*_philo(int i)
{
	t_data	*data;
	t_philo	*philo;

	data = _data();
	philo = &(data->philo[i]);
	return (philo);
}
