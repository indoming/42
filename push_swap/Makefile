# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 09:42:51 by indoming          #+#    #+#              #
#    Updated: 2022/04/22 13:33:10 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c push_swap_error.c push_swap_sorting.c dawn.c push_utils.c push_utils2.c ps_mov1.c ps_mov2.c ps_mov3.c index.c\

INCLUDE = ./libft

LIBFT = ./libft/libft.a

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	$(CC) $(FLAGS) libft.a -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT) libft.a

re:		fclean all clean

.PHONY: all clean fclean re
