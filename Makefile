# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:24:21 by fluchten          #+#    #+#              #
#    Updated: 2023/05/02 18:30:12 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Os -O2 -O3
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	game/game.c \
		game/hooks.c \
		game/moves.c \
		game/rotate.c \
		game/utils.c \
		graphics/algorithm.c \
		graphics/draw_map.c \
		graphics/raycasting.c \
		graphics/utils.c \
		parsing/colors.c \
		parsing/initialization.c \
		parsing/map_checks.c \
		parsing/map_closed.c \
		parsing/map.c \
		parsing/parsing.c \
		parsing/player.c \
		utils/errors.c \
		utils/free.c \
		main.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libs/libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/includes

MLX_PATH = libs/mlx
MLX_LIB	= ${MLX_PATH}/libmlx.a ${MLX_FLAGS}
MLX_INC = -I ${MLX_PATH}/
MLX_FLAGS = -framework OpenGL -framework AppKit

# COLOR_CYAN = \033[1;36m
# COLOR_RED = \033[0;31m
# COLOR_GREEN	= \033[0;32m
# COLOR_RESET = \033[0m

all: ${NAME}

${OBJS_DIR}:
# 	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}COMPILING ->${COLOR_RESET}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} ${MLX_INC} -c $< -o $@
# 	@echo "${COLOR_GREEN}.${COLOR_RESET}\c"

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	@make -sC ${MLX_PATH}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}
# 	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${OBJS_DIR} were created${COLOR_RESET}"
# 	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${NAME} was created${COLOR_RESET}"

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -sC ${MLX_PATH}
	@${RM} ${OBJS_DIR}
# @echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${OBJS_DIR} were deleted${COLOR_RESET}"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@${RM} ${NAME}
# @echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${NAME} was deleted${COLOR_RESET}"

re: fclean all

.PHONY: all clean fclean re
