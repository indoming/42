# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:42:52 by indoming          #+#    #+#              #
#    Updated: 2021/09/23 11:33:05 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf.c printf_dec.c printf_hex.c

INCLUDE = ./libft

LIBFT = ./libft/libft.a

CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT) a.out
re:		fclean all clean

.PHONY: all clean fclean re
