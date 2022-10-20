/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lea <lea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:11:24 by lea               #+#    #+#             */
/*   Updated: 2022/10/17 18:41:45 by lea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

/* LIBRARIES */
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* DEFINES */
# define YES	 1
# define NO 	 0
# define ODD	 1
# define EVEN	 0
# define TRUE	 1
# define FALSE	 0
# define SUCCESS 1
# define FAILURE 0

typedef	struct timeval t_timeval;

/* STRUCTS */
typedef struct s_philo
{
	int				num;
	int				nb_meal;
	int				finished;
	int				time_of_last_meal;
	pthread_t 		id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef	struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t baton_de_parole;
	pthread_mutex_t	is_everyone_alive_mutex;
}	t_mutex;

typedef struct s_data
{
	int			nb_philo;
	int			nb_meal_max;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			is_everyone_alive;
	t_mutex		mutex;
	t_philo		*philo;
	t_timeval	start_time;
}	t_data;

/* PROTOTYPES */
	/* CORE FOLDER */
		/* PHILO ROUTINE FILE */
void	*philo_routine(void *philo);
	/* PARSING FOLDER */
		/* CHECK_ARGS FILE*/
int		check_args(int ac, char **av);
	/* TOOLS FOLDER */
		/* CHECKING FILE */
int		everyone_alive_and_hungry(t_philo *philo);
		/* INIT FILE */
int		init_data(int ac, char **av);
void	init_philo(int i);
void	init_mutex(void);
		/* PTHREAD FILE */
int		pthread_create_philo(void);
void	pthread_join_philo(void);
		/* SINGLETON FILE */
t_data	*_data(void);
t_philo *_philo(int i);
		/* DIVERS FILE */
int		get_timestamp(void);
void 	free_all_data(void);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	print(int num, char *string);
/* NOT_LIBFT */
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
