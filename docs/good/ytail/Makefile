#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/08 12:19:27 by ytailor           #+#    #+#              #
#    Updated: 2014/01/19 13:35:41 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

SRCS = main.c getnbr.c ft_draw.c ft_raycasting.c ft_move.c ft_move2.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(CFLAGS) -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
