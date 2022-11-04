# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:59:01 by lea               #+#    #+#              #
#    Updated: 2022/11/04 22:44:55 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3 
NAME =		philosophers
ARG_PHILO =	5 510 200 200 20

INC_DIR =	inc

SRCS =		srcs/init/init_data.c		\
			srcs/init/init_mutex.c		\
			srcs/init/init_philo.c		\
			srcs/not_libft/ft_atoi.c	\
			srcs/not_libft/ft_isdigit.c	\
			srcs/parsing/check_args.c	\
			srcs/tools/check_status.c	\
			srcs/tools/divers.c			\
			srcs/tools/print.c			\
			srcs/tools/singleton.c		\
			srcs/tools/time.c			\
			srcs/main.c					\
			srcs/philo_routine.c		\
			srcs/pthread.c				\

OBJS =		$(SRCS:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -I ${INC_DIR} -pthread -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread

all:		$(NAME)

test:
			./$(NAME) $(ARG_PHILO)

test_mutex:
			valgrind --tool=helgrind ./$(NAME) $(ARG_PHILO)

test_leaks:
			valgrind ./$(NAME) $(ARG_PHILO)

clean:		
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re test test_mutex test_leaks
