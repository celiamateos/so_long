# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 20:52:58 by cmateos           #+#    #+#              #
#    Updated: 2023/06/27 16:48:27 by cmateos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #
COLOR_RESET = \x1b[0m
COLOR_RED = \x1b[1;31m
COLOR_GREEN = \x1b[1;32m
COLOR_YELLOW = \x1b[1;33m
COLOR_BLUE = \x1b[1;34m
COLOR_MAGENTA = \x1b[35m
COLOR_CYAN = \x1b[1;36m
BLANCO_T = \x1b[37m
BLANCO_F = \x1b[47m 
MAGENTA = \033[0;95m
BROWN =	\033[38;2;184;143;29m

# Archivo de salida que se generará:
NAME = so_long
BONUS_NAME = so_long_bonus
# Compilador que se usará:
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Crear una biblioteca estática (ar) y agregar archivos objeto a ella (r), 
# creándola si no existe (c) y añadiendo información de índice para facilitar la búsqueda de símbolos (s).
INCLUDE = so_long.h
INCLUDE_BONUS = so_long_bonus.h

SRC = ./src/so_long.c ./src/so_long_utils.c ./src/get_next_line_utils.c ./src/get_next_line.c ./src/ft_error.c \
	./src/ft_readmap.c ./src/ft_split.c  ./src/so_long_utils2.c ./src/ft_print_map.c ./src/ft_press_key.c \
	./src/ft_open_exit.c ./src/ft_check_path.c ./src/ft_win.c ./src/ft_printf.c ./src/ft_printf_utils.c ./src/ft_render.c \

SRC_BONUS =  ./src_bonus/so_long_bonus.c ./src_bonus/so_long_utils_bonus.c ./src_bonus/get_next_line_utils_bonus.c ./src_bonus/get_next_line_bonus.c ./src_bonus/ft_error_bonus.c \
	./src_bonus/ft_readmap_bonus.c ./src_bonus/ft_split_bonus.c  ./src_bonus/so_long_utils2_bonus.c ./src_bonus/ft_print_map_bonus.c ./src_bonus/ft_press_key_bonus.c \
	./src_bonus/ft_open_exit_bonus.c ./src_bonus/ft_check_path_bonus.c ./src_bonus/ft_end_game_bonus.c ./src_bonus/ft_printf_bonus.c ./src_bonus/ft_printf_utils_bonus.c ./src_bonus/ft_render_bonus.c ./src_bonus/ft_printsteps_bonus.c ./src_bonus/ft_animation.c \

# Define una lista de archivos objeto correspondientes a los archivos fuente.
# Sustituye la extensión .c por .o.
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

# Define la regla para crear name, el cual depende de obj y de include. 
# Se ejecuta el comando lib para crear name a partir de los objetos.

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) \

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME) \

# Establece una regla genérica para compilar archivos fuente (.c) en archivo objeto (.o).
# Se utiliza el compilador $(CC) con las banderas $(CFLAGS) para compilar el archivo fuente y generar el archivo objeto.

%.o: %.c
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(COLOR_GREEN) Created! :3 $(COLOR_RESET)"

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@echo "$(COLOR_BLUE) Cleaned all! $(COLOR_RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
