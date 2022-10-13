/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:40:20 by lea               #+#    #+#             */
/*   Updated: 2022/10/13 23:38:06 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	everyone_alive_and_hungry(t_philo *philo)
{
	t_data	*data;

	data = _data();
	printf("everyone : %d\n", data->is_everyone_alive);
	if (data->is_everyone_alive == TRUE && philo->nb_meal <= data->nb_meal_max)
		return (TRUE);
	else
		return (FALSE);
}
