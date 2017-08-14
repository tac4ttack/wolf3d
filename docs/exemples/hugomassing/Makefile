# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmassing <hmassing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/10 17:32:19 by hmassing          #+#    #+#              #
#    Updated: 2014/01/31 17:15:15 by hmassing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = wolf3d

FLAG = -Wall -Wextra -Werror -g

SRC = wolf3d.c get_next_line.c draw.c raycast.c controls.c

RM = rm -f

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

INC = -I /usr/X11/include/X11

LIBFT = -L./lib -lft

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re


all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ $(INC)

$(NAME): $(OBJ)
		cd lib/ && make
		$(CC) $(FLAG) $(OBJ) -o $(NAME) $(INC) $(MLX) $(LIBFT)


clean:
		$(RM) $(OBJ)
		cd lib/ && make clean

fclean: clean
		$(RM) $(NAME)
		cd lib/ && make fclean

re: fclean all

.PHONY: all clean fclean re
