PURP = \e[35m
GREEN = \e[32m
GREEN2 = \033[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \033[33m
ORANGE = $(shell tput setaf 208)
HIDDEN = \e[8m
RESET = \e[0
BLUE = \033[34m
CYAN = \033[36m

NAME = draw_pixel
HEAD = draw_pixel.h

SRCS 	= ./srcs/draw_pixel.c

OBJS 	= ${SRCS:.c=.o}
MAIN	= ./srcs/draw_pixel.c

LIB = utils/libft/libft.a utils/ft_printf/libftprintf.a utils/mlx/libmlx.a

MLX_PATH = ./mlx/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -Imlx #-g -fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit


AR = ar rc
RM = rm -f

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@echo "$(GREEN2)ð Link paths"
					@$(MAKE) -C $(LBFT_PATH)
					@$(MAKE) -C $(MLX_PATH)
					@$(MAKE) -C $(PRINTF_PATH)
					@$(CC) $(CFLAGS) ${OBJS} -o $(NAME) $(LIB) $(MLXFLAGS)
					@printf "$(BLUE)ðµ Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(CYAN)Cub3D Compiled ! \033[39m(\033[31mà¹\033[39mâ¹â¡â¹\033[31mà¹\033[39m)"
					@sleep 0.2

clean:
					@${RM} ${OBJS}
					@echo "$(YELLOW)---- Cleaning library ----"
					@sleep 0.2
					@printf "$(BLUE)ð§½ Cleaning $(NAME)$(RESET)\n"
					@$(MAKE) -C $(LBFT_PATH) clean
					@$(MAKE) -C $(MLX_PATH) clean
					@$(MAKE) -C $(PRINTF_PATH) clean
					@echo "$(GREEN2)ð Cleaning paths"
					@sleep 0.2
					@echo "$(YELLOW)Cub3D is all clean ! $(ORANGE)(ï¾âã®â)ï¾$(YELLOW)*:ï½¥ï¾â§"
					@sleep 0.2

fclean: 	clean
					@${RM} $(NAME)
					@$(MAKE) -C $(LBFT_PATH) fclean
					@$(MAKE) -C $(PRINTF_PATH) fclean
#					@$(MAKE) -C $(MLX_PATH) fclean
					@echo "\033[31mEverything is deleting now ! Â¯\_(ã)_/Â¯"
					@sleep 0.2
					@printf "\r$(PURP)ð  $(NAME) have been removed$(RESET)\n"
					@sleep 0.2

re:			fclean all

.PHONY: all clean fclean re party
