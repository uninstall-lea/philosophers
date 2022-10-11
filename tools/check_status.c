/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/03 19:28:02 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	everyone_alive_and_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (data->is_everyone_alive == TRUE && philo->nb_meal <= data->nb_meal_max)
		return (TRUE);
	else
		return (FALSE);
}
