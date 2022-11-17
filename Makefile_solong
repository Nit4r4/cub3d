# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:30:27 by vferraro          #+#    #+#              #
#    Updated: 2022/05/04 15:42:38 by vferraro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/so_long.c \
	utils/get_next_line/get_next_line.c \
	utils/get_next_line/get_next_line_utils.c	\
	src/draw_map.c \
	src/put_img_to_window.c \
	src/checkmap.c \
	src/errors.c \
	src/inits.c \
	src/captain_hook.c \
	src/moves.c \
	src/move_fox_to_left.c 
CFLAGS = -Wall -Werror -Wextra -Imlx #-g -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit
LIB = utils/libft/libft.a utils/ft_printf/libftprintf.a utils/mlx/libmlx.a
CC = gcc
NAME = so_long
OBJS = ${SRCS:.c=.o}
MLX_PATH = ./utils/mlx/
LBFT_PATH = ./utils/libft/
PRINTF_PATH = ./utils/ft_printf/
AR = ar rc
RM = rm -f

all: ${NAME}

@ar -rcs $(NAME):	$(OBJS)
		@$(MAKE) -C $(LBFT_PATH)
		@$(MAKE) -C $(MLX_PATH)
		@$(MAKE) -C $(PRINTF_PATH)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(MLXFLAGS) $(LIB)

%o:	%.c
	$(CC) $(CFLAGS) -I ${MLX_PATH} -I ${LBFT_PATH} -I ${PRINTF_PATH} -c $< -o $@

clean: 
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re