# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:33:02 by indoming          #+#    #+#              #
#    Updated: 2022/03/07 12:38:26 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_SERVER = server.c
SRC_CLIENT = client.c

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

INCLUDE = ./libft

LIBFT = ./libft/libft.a

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

OBJS_SERVER = $(SRC_SERVER : .c=.o)
OBJS_CLIENT = $(SRC_CLIENT : .c=.o)

OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS : .c=.o)
OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS : .c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	$(CC) $(FLAGS) $(SRC_SERVER) libft.a -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	$(CC) $(FLAGS) $(SRC_CLIENT) libft.a -o $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	$(CC) $(FLAGS) $(SRC_SERVER_BONUS) libft.a -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(INCLUDE)
	make -C $(INCLUDE)
	cp libft/libft.a .
	$(CC) $(FLAGS) $(SRC_CLIENT_BONUS) libft.a -o $(NAME_CLIENT_BONUS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	rm -rf $(LIBFT) libft.a

re:		fclean all clean

.PHONY: all clean fclean re
