# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 21:25:49 by fmessina          #+#    #+#              #
#    Updated: 2017/09/29 21:02:50 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 					wolf3d

CC = 					clang
CFLAGS +=				-Wall -Wextra -Werror
OFLAGS := 				-O3 -Ofast
RM := 					rm -rf

INC = 					$(addprefix $(INC_PATH)/,$(INC_NAMES))
INC_PATH =				./includes
INC_NAMES =				wolf3d.h

LIBFT :=				$(LIBFT_PATH)/libft.a
LIBFT_PATH :=			./libft
LIBFT_INC_PATH :=		$(LIBFT_PATH)/
LIBFTFLAGS :=			-lft

LIBMATHFLAGS :=			-lm

RENTER :=				-DREENTRANT
PTHREADFLAG :=			-lpthread

SDL2TTFLIB :=			-lSDL2_ttf

OBJ =					$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_PATH =				./obj
OBJ_NAME =				$(SRC_NAME:.c=.o)

SRC =					$(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_PATH =				./src
SRC_NAME =				coord.c \
						debug.c \
						events.c \
						core.c \
						loop.c \
						main.c \
						map.c \
						map_data.c \
						move.c \
						player.c \
						raycasting.c \
						render.c \
						text.c \
						texture.c \
						toggle.c \
						utils.c

default: all

help: usage

all: brew compile

$(NAME): $(SRC) $(INC) $(OBJ_PATH) $(OBJ)
	@echo "Compiling $(NAME)"
	$(CC) -o $@ $(OBJ) -L$(LIBFT_PATH) $(LIBFTFLAGS) $(LIBMATHFLAGS) $(SDL2LIB) $(SDL2TTFLIB) $(PTHREADFLAG) $(ASANFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES_PATH) $(INC)
	$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_INC_PATH) $(SDL2CFLAGS) $(RENTER) $(ASANFLAGS)
	
$(OBJ_PATH):
	@echo "Creating ./obj path and making binaries from source files"
	@mkdir $(OBJ_PATH)

brew:
	@echo "$(GREEN)Updating brew packages$(EOC)"
	brew upgrade
	@echo "$(GREEN)Checking pkg-config presence$(EOC)"
	brew -v install pkg-config
	@echo "$(GREEN)Checking libpng presence$(EOC)"
	brew -v install libpng
	@echo "$(GREEN)Checking SDL2 presence$(EOC)"
	brew -v install sdl2
	@echo "$(GREEN)Checking freetype2 presence$(EOC)"
	brew -v install freetype
	@echo "$(GREEN)Checking SDL2_ttf presence$(EOC)"
	brew -v install sdl2_ttf

sdl2lib:
	$(eval SDL2LIB = $(shell sdl2-config --libs))
sdl2cflags:
	$(eval SDL2CFLAGS = $(shell sdl2-config --cflags))

debug: debuglibft
	$(eval ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer -g)

fcleanbrew:
	brew uninstall -f sdl2_ttf
	brew uninstall -f freetype
	brew uninstall -f pkg-config
	brew uninstall -f libgpng
	brew uninstall -f sdl2

COMPILE: libft sdl2lib sdl2cflags $(NAME)
compile: COMPILE

clean: cleanlibft
	@echo "Cleaning..."
	@echo "Deleting .obj files"
	@rm -rf $(OBJ_PATH)

fclean: clean fcleanlibft
	@echo "Full cleaning..."
	@echo "Deleting $(NAME) executable and config file"
	@make -C $(LIBFT_PATH)/ fclean
	@rm -rf $(NAME) ./config

libft:
	@echo "Compiling Libft library"
	make -C $(LIBFT_PATH)/ all

debuglibft:
	@echo "Compiling Libft library with ASan"
	make -C $(LIBFT_PATH)/ debug all
	
cleanlibft:
	@echo "Cleaning the Libft"
	make -C $(LIBFT_PATH)/ clean

fcleanlibft:
	@echo "Cleaning the Libft"
	make -C $(LIBFT_PATH)/ fclean

re: fclean all

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)

usage:
	@echo "\n$(B_RED)Please use one of the following command:$(EOC)\n"
	@echo "Compile $(GREEN)$(NAME)$(EOC) -> $(B_YELL)make compile$(EOC)\n"
	@echo "Compile with $(GREEN)debug mode$(EOC) activated -> $(B_YELL)make debug compile$(EOC)\n"	

.PHONY: default help all brew sdl2lib sdl2cflags debug fcleanbrew COMPILE compile clean fclean libft debuglibft cleanlibft fcleanlibft re norme usage

GREY =					\x1b[2;29m
BLACK =					\x1b[2;30m
RED =					\x1b[2;31m
GREEN =					\x1b[2;32m
YELL =					\x1b[2;33m
BLUE =					\x1b[2;34m
PINK =					\x1b[2;35m
CYAN =					\x1b[2;36m
WHIT =					\x1b[2;37m
WHIBLK =				\x1b[2;40m
WHIRED =				\x1b[2;41m
WHIGRE =				\x1b[2;42m
WHIYEL =				\x1b[2;43m
WHIBLU =				\x1b[2;44m
WHIPI =					\x1b[2;45m
WHICYA =				\x1b[2;46m
B_GREY =				\x1b[1;29m
B_BLACK =				\x1b[1;30m
B_RED =					\x1b[1;31m
B_GREEN =				\x1b[1;32m
B_YELL =				\x1b[1;33m
B_BLUE =				\x1b[1;34m
B_PINK =				\x1b[1;35m
B_CYAN =				\x1b[1;36m
B_WHIT =				\x1b[1;37m
B_WHIBLK =				\x1b[1;40m
B_WHIRED =				\x1b[1;41m
B_WHIGRE =				\x1b[1;42m
B_WHIYEL =				\x1b[1;43m
B_WHIBLU =				\x1b[1;44m
B_WHIPI =				\x1b[1;45m
B_WHICYA =				\x1b[1;46m
U_GREY =				\x1b[4;29m
U_BLACK =				\x1b[4;30m
U_RED =					\x1b[4;31m
U_GREEN =				\x1b[4;32m
U_YELL =				\x1b[4;33m
U_BLUE =				\x1b[4;34m
U_PINK =				\x1b[4;35m
U_CYAN =				\x1b[4;36m
U_WHIT =				\x1b[4;37m
U_WHIBLK =				\x1b[4;40m
U_WHIRED =				\x1b[4;41m
U_WHIGRE =				\x1b[4;42m
U_WHIYEL =				\x1b[4;43m
U_WHIBLU =				\x1b[4;44m
U_WHIPI =				\x1b[4;45m
U_WHICYA =				\x1b[4;46m
IC_GREY =				\x1b[2;29m
IC_BLACK =				\x1b[2;30m
IC_RED =				\x1b[2;31m
IC_GREEN =				\x1b[2;32m
IC_YELL =				\x1b[2;33m
IC_BLUE =				\x1b[2;34m
IC_PINK =				\x1b[2;35m
IC_CYAN =				\x1b[2;36m
IC_WHIT =				\x1b[2;37m
IC_WHIBLK =				\x1b[2;40m
IC_WHIRED =				\x1b[2;41m
IC_WHIGRE =				\x1b[2;42m
IC_WHIYEL =				\x1b[2;43m
IC_WHIBLU =				\x1b[2;44m
IC_WHIPI =				\x1b[2;45m
IC_WHICYA =				\x1b[7;46m
EOC =					\x1b[0m
