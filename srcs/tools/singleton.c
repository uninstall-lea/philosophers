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

void    ft_bzero(void *s, size_t n)
{
	// la changer de place
    char    *adresse;
    int        i;

    adresse = s;
    i = 0;
    while (n)
    {
        adresse[i] = 0;
        i++;
        n--;
    }
}

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

t_philo *_philo(int i)
{
	t_data	*data;
	t_philo	*philo;

	data = _data();
	philo = &(data->philo[i]);
	return (philo);
}
