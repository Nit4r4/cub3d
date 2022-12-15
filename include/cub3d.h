/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:55 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/15 11:07:37 by vferraro         ###   ########.fr       */
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
# include "../utils/libft/libft.h"
//# include "../utils/get_next_line/get_next_line.h"
# include "../utils/mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"

/* DEFINE COLORS HEX*/
# define BLOOD 0x8d0b0b
# define GREY 0xcecece
# define WHITE 0xffffff
# define BLACK 0x000000

# define PURP "\e[35m"
# define GREEN "\e[32m"
# define RED "\e[31m"
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

/* DEFINE SIZES */
# define WIN_WID 800
# define WIN_HEI 500
# define IMG_X 32
# define IMG_Y 32

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
# define ERR_FILE "> Le fichier n'est pas au bon format\n"
# define ERR_KEY "Misclick ? Touche non valide\n"
# define BAD_CHAR "> there is a bad char on your map\n"
# define BAD_MAP "> map is not correct\n"
# define ERR_WIN "> No window here...sooooo dark\n"


/* ACTIONS MESSAGES */
# define M_MSG "Inclure le message voulu ici"

/* STRUCT */
typedef struct s_map
{
	char	**map;
	int		nblines;
	int		hei;
	int		wid;
	int		mmap_size;
//	size_t		map_size;
}		t_map;

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*mlx_add;
	int		mlx_bpp;
	int		mlx_nd; //endian
	int		mlx_len;
	int		move;
	t_map	map;
	//t_vect	pos;
}	t_cub;

typedef struct s_vect
{
	int		pos;
	float	x;
	float	y;
}	t_vect;

typedef struct s_player
{
	t_vect	pos; 
	t_vect	dir;
	t_vect	old;
	char	cardi;// ?
}	t_player;

/* UTILS */

/* MANDATORY */
void	init_game(void);
void	init_pos(t_cub *cub);

void	critical_errors(char *str);
int		read_map(t_cub *cub, char *file);
int		color_map(t_cub *cub);
//int		color_map(t_cub *cub, int i, int j, int color);
int		a_little_bit( t_cub *cub);
int		move_your_body(int o_key, t_cub *cub);
int		in_key_s_hook(int o_key, t_cub *cub);
void	error_close(char *str);



/* BONUS (ON Y CROIT) */


#endif
