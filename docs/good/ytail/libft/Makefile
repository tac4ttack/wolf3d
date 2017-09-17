#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:25:45 by ytailor           #+#    #+#              #
#    Updated: 2014/01/18 10:58:48 by amorfan          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FILE = ft_memset \
	ft_bzero \
	ft_count_word \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlen \
	ft_strdup \
	ft_strndup \
	ft_strcpy \
	ft_strncpy \
	ft_strcat \
	ft_strncat \
	ft_strchr \
	ft_strrchr \
	ft_strstr \
	ft_strnstr \
	ft_strcmp \
	ft_strncmp \
	ft_atoi \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_strlcat \
	ft_memalloc \
	ft_memdel \
	ft_strnew \
	ft_putchar \
	ft_putstr \
	ft_strdel \
	ft_strclr \
	ft_striter \
	ft_striteri \
	ft_strmap \
	ft_strmapi \
	ft_strequ \
	ft_strnequ \
	ft_strsub \
	ft_strjoin \
	ft_strtrim \
	ft_putnbr \
	ft_putendl \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_strsplit \
	ft_itoa \
	ft_printf \
	ft_putchar_count \
	get_next_line

SRC = $(addsuffix .c, $(FILE))

OFILES = $(addsuffix .o, $(FILE))


all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) -I ./includes
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: @fclean all
