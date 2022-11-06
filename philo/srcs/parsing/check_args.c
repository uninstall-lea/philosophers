/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:03:18 by lea               #+#    #+#             */
/*   Updated: 2022/11/05 19:39:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{	
		printf("Wrong number of args given\n");
		return (FAILURE);
	}
	if (ft_atoi(av[1]) <= 0)
	{
		printf("Wrong number of philos given 👻\n");
		return (FAILURE);
	}
	if (ft_atoi(av[1]) > 200)
	{
		printf("Aie aie aie, tu vas tout casser 😱 !!\n");
		return (FAILURE);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Donne plus de temps radin !\n");
		return (FAILURE);
	}
	if (ac == 6 && ft_atoi(av[5]) <= 0)
	{
		printf("You can't eat a negative amount of time !\n");
		return (FAILURE);
	}
	return (SUCCESS);
}