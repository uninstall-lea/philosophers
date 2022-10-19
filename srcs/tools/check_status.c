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

#include "philosophers.h"

int	time_since_last_meal(t_philo *philo)
{
	int	current_time;

	current_time = get_timestamp();
	return (current_time - philo->time_of_last_meal);

}

void	check_death(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (time_since_last_meal(philo) > data->time_to_die)
	{
		pthread_mutex_lock(&(data->mutex.baton_de_parole));
		print(philo->num, "died");
		pthread_mutex_unlock(&(data->mutex.baton_de_parole));
		pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
		data->is_everyone_alive = FALSE;
		pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
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
