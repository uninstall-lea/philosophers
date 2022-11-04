/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/11/04 22:16:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*void	check_death(t_philo *philo)
{
	t_data		*data;

	data = _data();
	if (time_since_last_meal(philo) > data->time_to_die)
	{
		pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
		data->is_everyone_alive = FALSE;
		pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
	}
}
*/
void	check_usleep_death(int sleep, t_philo *philo)
{
	/*fonction changee pour décalage de usleep */
	int	start_time;
	int	end_time;
	int	current_time;

	start_time = get_timestamp();
	end_time = start_time + sleep;
	//printf("num : %d / start : %d / end : %d\n", philo->num, start_time, end_time);
	current_time = start_time;
	while (current_time < end_time && is_everyone_alive(philo) == TRUE)
	{	
		usleep(500);
		//check_death(philo);
		current_time = get_timestamp();
	}
	//printf("%d / num : %d end usleep\n", get_timestamp(), philo->num);
}

int		is_everyone_alive(t_philo *philo)
{
	int		tmp;
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&(data->mutex.is_everyone_alive_mutex));
	if (time_since_last_meal(philo) > data->time_to_die)
		data->is_everyone_alive = FALSE;
	tmp = data->is_everyone_alive;
	pthread_mutex_unlock(&(data->mutex.is_everyone_alive_mutex));
	return (tmp);
}

int	everyone_alive_and_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	//check_death(philo);
	if (is_everyone_alive(philo) == TRUE && philo->nb_meal <= data->nb_meal_max)
		return (TRUE);
	else if (is_everyone_alive(philo) == FALSE)
	{
		print_death(philo);
		return (FALSE);
	}
	else
		return (FALSE);
}
