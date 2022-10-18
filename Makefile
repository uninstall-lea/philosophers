# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lea <lea@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:59:01 by lea               #+#    #+#              #
#    Updated: 2022/10/17 18:21:18 by lea              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3 
NAME =		philosophers

INC_DIR =	inc

SRCS =		srcs/init/init_data.c		\
			srcs/init/init_mutex.c		\
			srcs/init/init_philo.c		\
			srcs/not_libft/ft_atoi.c	\
			srcs/not_libft/ft_isdigit.c	\
			srcs/parsing/check_args.c	\
			srcs/tools/check_status.c	\
			srcs/tools/singleton.c		\
			srcs/tools/divers.c			\
			srcs/main.c					\
			srcs/philo_routine.c		\
			srcs/pthread.c				\

OBJS =		$(SRCS:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -I ${INC_DIR} -pthread -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread

all:		$(NAME)

clean:		
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
