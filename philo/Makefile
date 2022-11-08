# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:59:01 by lea               #+#    #+#              #
#    Updated: 2022/11/08 13:21:10 by lbisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3 
NAME =		philosophers
ARG_PHILO =	20 500 200 200

RESET =		"\033[0m"
BOLDGREEN = "\033[1m\033[32m"

INC_DIR =	inc

SRCS =		srcs/init/init_data.c		\
			srcs/init/init_mutex.c		\
			srcs/init/init_philo.c		\
			srcs/not_libft/ft_atoi.c	\
			srcs/not_libft/ft_bzero.c	\
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
			@$(CC) $(CFLAGS) -I ${INC_DIR} -pthread -c $< -o $@
			@echo Currently compiling $<

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread
			@echo Executable file has been created successfully
			@echo 🦖$(BOLDGREEN) Compilation completed! $(RESET)🦖

all:		$(NAME)

test:
			./$(NAME) $(ARG_PHILO)

test_mutex:
			valgrind --tool=helgrind ./$(NAME) $(ARG_PHILO)

test_leaks:
			valgrind ./$(NAME) $(ARG_PHILO)

clean:
			@rm -rf $(OBJS)
			@echo All the .o files have been removed successfully

fclean:		clean
			@rm -rf $(NAME)
			@echo Executable file has been removed successfully

re:			fclean all

.PHONY:		all clean fclean re test test_mutex test_leaks
