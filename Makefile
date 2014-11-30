# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by ybarbier          #+#    #+#              #
#    Updated: 2014/11/28 16:17:56 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_lst.c \
		ft_arg.c \
		ft_ls.c \
		ft_error.c \
		main.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	# make -C libft/ fclean
	# make -C libft/
	# $(CC) $(CFLAGS) -I libft/includes/ -c $(SRC)
	# $(CC) $(CFLAGS) -c main.c
	$(CC) -o $(NAME) $(OBJ) libft/libft.a
	# $(CC) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
