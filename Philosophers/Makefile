# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkiala <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:34:04 by gkiala            #+#    #+#              #
#    Updated: 2024/10/11 11:35:07 by gkiala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = ft_philo_life.c ft_utils.c ft_pthreads.c ft_init_program.c ft_actions.c main.c

CC = cc

FLAGS = -Wall -Werror -lpthread

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
		

clean :
	/bin/rm -rf $(OBJS)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
