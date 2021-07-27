# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 17:29:23 by indoming          #+#    #+#              #
#    Updated: 2021/07/27 13:31:58 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FOLDER = sources

INCLUDE_DIR = library

SRC_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c\
 ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_calloc.c\

SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_FILES))

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_O = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
		ar rcs $(NAME) $(SRC_O)

%.o: %.c
	$(CC) ${FLAGS} -I ${INCLUDE_DIR} -o $@ -c $<

clean:
	rm -rf  $(SRC_O)

fclean: clean
		rm -rf $(NAME)

re: 	fclean all clean

cleanall: 
	rm *.o *.a a.out