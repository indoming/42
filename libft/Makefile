# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 17:29:23 by indoming          #+#    #+#              #
#    Updated: 2021/08/16 09:59:29 by indoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c\
 ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_calloc.c\
 \
 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
ft_lstclear.c ft_lstiter.c ft_lstmap.c\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:.c=.o)
BONUS_O = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) ${FLAGS} -o $@ -c $<

clean:
	rm -rf  $(OBJS) $(BONUS_O)

fclean: clean
		rm -rf $(NAME)

re: 	fclean all clean

bonus:	$(BONUS_O)
			ar rcs $(NAME) $(BONUS_O)

.PHONY: all clean fclean re bonus
