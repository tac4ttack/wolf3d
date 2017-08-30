# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 21:25:49 by fmessina          #+#    #+#              #
#    Updated: 2017/08/30 14:47:48 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 					wolf3d

CC = 					clang
CFLAGS +=				-Wall -Wextra -Werror
OFLAGS := 				-O3
RM := 					rm -rf

INC = 					$(addprefix $(INC_PATH)/,$(INC_NAMES))
INC_PATH =				./includes
INC_NAMES =				wolf3d.h

LIBFT :=				$(LIBFT_PATH)/libft.a
LIBFT_PATH :=			./libft
LIBFT_INC_PATH :=		$(LIBFT_PATH)/
LIBFTFLAGS :=			-lft

LIBMATHFLAGS :=			-lm

SDL2 :=					libSDL2.a
SDL2_PATH :=			./SDL2/lib
SDL2_INC_PATH :=		./SDL2/include/SDL2
SLD2FLAGS :=			-lSDL2

OBJ =					$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_PATH =				./obj
OBJ_NAME =				$(SRC_NAME:.c=.o)

SRC =					$(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_PATH =				./src
SRC_NAME =				color.c \
						coord.c \
						debug.c \
						drawing.c \
						events.c \
						init.c \
						loop.c \
						main.c \
						map.c \
						map_data.c \
						raycasting.c \
						test.c \
						utils.c

default: usage

all: $(NAME)

$(NAME): libft $(SDL2_PATH)/$(SDL2) $(SRC) $(INC) $(OBJ_PATH) $(OBJ)
	@echo "Compiling $(NAME)"
	$(CC) -o $@ $(OBJ) -L$(LIBFT_PATH) $(LIBFTFLAGS) $(LIBMATHFLAGS) -L$(SDL2_PATH) $(SLD2FLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES_PATH) $(INC)
	$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_INC_PATH) -I $(SDL2_INC_PATH) $(DEBUG)

$(OBJ_PATH):
	@echo "Creating ./obj path and making binaries from source files"
	@mkdir $(OBJ_PATH)

$(SDL2_PATH)/$(SDL2):
	rm -rf SDL2/trash/SDL2-2.0.5.tar.gz SDL2/trash/SDL2-2.0.5
	mkdir -p SDL2/trash
	curl -O https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
	tar xf SDL2-2.0.5.tar.gz
	(cd SDL2-2.0.5 \
	&& ./configure CC=clang --prefix=$(shell pwd)/SDL2/ \
	&& $(MAKE) CC=clang && $(MAKE) CC=clang install )
	mv SDL2-2.0.5.tar.gz SDL2-2.0.5 SDL2/trash

COMPILE: all
compile: COMPILE

debug: debug_flag
debug_flag:
	$(eval DEBUG = -DDEBUG -g)

clean:
	@echo "Cleaning..."
	@echo "Deleting .obj files"
	@rm -rf $(OBJ_PATH)

fclean: cleansdl2 clean 
	@echo "Full cleaning..."
	@echo "Deleting $(NAME) executable and config file"
	@rm -rf $(NAME) ./config

libft:
	@echo "Compiling Libft library"
	make -C $(LIBFT_PATH)/ all

cleansdl2:
	@echo "Full cleaning SDL2"
	$(RM) ./SDL2/

re: fclean all

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)

usage:
	@echo "\n$(B_RED)Please use one of the following command:$(EOC)\n"
	@echo "Compile $(GREEN)$(NAME)$(EOC) -> $(B_YELL)make compile$(EOC)\n"
	@echo "Compile with $(GREEN)debug mode$(EOC) activated -> $(B_YELL)make debug compile$(EOC)\n"
	@echo "If you want to activate the debug mode, be sure to do a 'make fclean' first\n"
	

.PHONY: all clean fclean re libft sdl

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
