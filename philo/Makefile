# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbisson <lbisson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:59:01 by lea               #+#    #+#              #
#    Updated: 2022/11/11 19:03:59 by lbisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g3 -MMD
NAME =		philosophers
ARG_PHILO =	5 800 200 200 

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
DEPS =		$(SRCS:.c=.d)

%.o: %.c
			@$(CC) $(CFLAGS) -I ${INC_DIR} -pthread -c $< -o $@
			@echo Currently compiling $<

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread
			@make wait
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
			@rm -rf $(OBJS) $(DEPS)
			@echo All the .o and .d files have been removed successfully

wait:
			@echo -n "\r  5%  [\033[0;31m█\033[m.........................]"
			@sleep 0.1
			@echo -n "\r 10%  [\033[0;31m███\033[m.......................]"
			@sleep 0.1
			@echo -n "\r 15%  [\033[0;31m████\033[m......................]"
			@sleep 0.1
			@echo -n "\r 20%  [\033[0;31m██████\033[m....................]"
			@sleep 0.1
			@echo -n "\r 27%  [\033[0;31m████████\033[m..................]"
			@sleep 0.1
			@echo -n "\r 32%  [\033[0;31m██████████\033[m................]"
			@sleep 0.1
			@echo -n "\r 35%  [\033[0;31m███████████\033[m...............]"
			@sleep 0.1
			@echo -n "\r 45%  [\033[0;31m█████████████\033[m.............]"
			@sleep 0.1
			@echo -n "\r 50%  [\033[0;31m███████████████\033[m...........]"
			@sleep 0.1
			@echo -n "\r 65%  [\033[0;31m██████████████████\033[m........]"
			@sleep 0.1
			@echo -n "\r 80%  [\033[0;31m█████████████████████\033[m.....]"
			@sleep 0.1
			@echo -n "\r 90%  [\033[0;31m████████████████████████\033[m..]"
			@sleep 0.1
			@echo -n "\r 95%  [\033[0;31m█████████████████████████\033[m.]"
			@sleep 0.1
			@echo -n "\r 99%  [\033[0;31m██████████████████████████\033[m]"
			@sleep 1
			@echo -n "\r 100% [\033[0;32m██████████████████████████\033[m]\033[0;32m\n\033[0;m"

fclean:		clean
			@rm -rf $(NAME)
			@echo Executable file has been removed successfully

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re
