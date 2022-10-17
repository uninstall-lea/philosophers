/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/17 18:25:02 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

void	check_death(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (philo->time_since_last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&(data->mutex.baton_de_parole));
		printf("%d %d died\n", get_timestamp(), philo->num);
		pthread_mutex_unlock(&(data->mutex.baton_de_parole));
		data->is_everyone_alive = FALSE;
	}
}

int	everyone_alive_and_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	check_death(philo);
	if (data->is_everyone_alive == TRUE && philo->nb_meal <= data->nb_meal_max)
		return (TRUE);
	else
		return (FALSE);
}
