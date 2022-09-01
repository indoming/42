# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 10:00:01 by indoming          #+#    #+#              #
#    Updated: 2022/08/22 13:08:44 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo_args.c actions.c time.c\

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all clean

.PHONY: all clean fclean re
