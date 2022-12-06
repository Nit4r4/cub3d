/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:05:42 by creyt             #+#    #+#             */
/*   Updated: 2022/11/29 16:11:25 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_PIXEL_H
# define DRAW_PIXEL_H

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
# include "../mlx/mlx.h"

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

/* ACTIONS MESSAGES */
# define M_MSG "Inclure le message voulu ici"

/* STRUCT */

typedef struct s_map
{
	char	**map;
	int		nblines;
	int		hei;
	int		wid;
}		t_map;
/*
typedef struct s_args
{

}	t_args;
*/
typedef struct s_cub
{
	void	*mlx_ptr;
	t_map	map;
}	t_cub;

/* UTILS */
//void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title);

/* MANDATORY */

/* BONUS (ON Y CROIT) */

//MAIS BIEN SUR !!

#endif
