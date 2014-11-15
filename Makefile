# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2014/11/15 13:36:57 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	$(PATH_SRC)ft_ls.c \
		$(PATH_SRC)main.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean
	make -C libft/
	$(CC) $(CFLAGS) -I libft/includes/ -c ft_ls.c
	$(CC) $(CFLAGS) -c main.c
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

