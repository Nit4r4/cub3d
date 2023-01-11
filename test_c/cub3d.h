/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:55 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/16 10:31:35 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* INCLUDE LIBRARY */
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

/* INCLUDE PATHES */
# include "./utils/libft/libft.h"
# include "./utils/get_next_line/get_next_line.h"
# include "./utils/mlx/mlx.h"
# include "./utils/ft_printf/ft_printf.h"

/* DEFINE COLORS */
# define PURP "\e[35m"
# define GREEN "\e[32m"
# define RED "\e[31m"
# define WHITE "\e[39m"
# define YELLOW "\033[33m"
# define ORANGE "$(shell tput setaf 208)"
# define RESET "\e[0"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

/* DEFINE IMAGES */
# define IMG_G "./img_xpm/vide_HERBE_32x32.xpm"
# define IMG_W "./img_xpm/mur_arbre_32x32C2.xpm"
# define IMG_P "./img_xpm/fox.xpm"
# define IMG_PL "./img_xpm/foxL.xpm"
# define IMG_I "./img_xpm/item_32x32_smallApple.xpm"
# define IMG_E "./img_xpm/end32x32_flip.xpm"
# define ERR_TXT "Error\n"

/* DEFINE SIZES */
# define WIN_WID 800
# define WIN_HEI 500
# define IMG_X 32
# define IMG_Y 32

/*DEFINE CHAR */
# define IS_SPACE " \n\t\v\f\r"
# define IS_PLAYER "NSWE"
# ifndef IS_MAP
#  define IS_MAP "01NSWE"
# endif

/* DEFINE KEYS */
# define ESC 53
# define RED_CROSS 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ARROW_L 123
# define ARROW_R 124
# define ARROW_DW 125
# define ARROW_UP 126

/* ERRORS MESSAGES */
# define ERROR "Error\n"
# define ERR_ARG "\033[31mError : bad number of arguments"
# define ERR_FILE "> the file must be .cub\n"
# define ERR_FD "not found file to read\n"
# define BAD_CHAR "> there is a bad char on your map\n"
# define BAD_MAP "> map is not correct\n"
# define ERR_MAP_INFO " > infos on the map are wrong\n"
# define MAP_ERR_HO "The map is like the Emmental!\n"
# define MAP_ERR_HO_2 "The map is like the Gruyere!\n"
# define ERR_MALLOC "Error\nCannot allocate memory\n"
# define ERR_MAP_CONTENT "Error\nInvalid content map\n"
# define ERR_MAP_SIZE "Error\nInvalid size map\n"
# define ERR_MAP_PLAYER "Error\nInvalid player map\n"

/* ACTIONS MESSAGES */
# define M_MSG "Inclure le message voulu ici"

/* STRUCT */

typedef struct s_map
{
	char	**info; // tout le fichier
	char	*map;
	char	**tabmap;
	int		nb_lines;
	int		len_line;
	int		hei;
	int		wid;
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*fl;
	char	*cei;
	int		floor;
	int		ceiling;
}		t_map;

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*addr;
	char	*mlx_add;
	int		mlx_bpp;
	int		mlx_nd; //endian
	int		mlx_len;
	int		move;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}	t_cub;

/* UTILS */
//void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title);

/* MANDATORY */
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);

/* BONUS (ON Y CROIT) */

//MAIS BIEN SUR !!

#endif
