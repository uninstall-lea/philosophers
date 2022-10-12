/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:01 by lea               #+#    #+#             */
/*   Updated: 2022/10/12 15:36:40 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

	data = _data();
	return (&(data->philo[i]));
}
