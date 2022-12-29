/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:55 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/29 16:37:49 by creyt            ###   ########.fr       */
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
# include <math.h>

/* INCLUDE PATHES */
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
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
# define IMG_G "./img_xpm/vide_HERBE_32x32.xpm" //les images a changer ??
# define IMG_W "./img_xpm/mur_arbre_32x32C2.xpm"
# define IMG_P "./img_xpm/fox.xpm"
# define IMG_PL "./img_xpm/foxL.xpm"
# define IMG_I "./img_xpm/item_32x32_smallApple.xpm"
# define IMG_E "./img_xpm/end32x32_flip.xpm"
# define ERR_TXT "Error\n"

/* DEFINE SIZES */
# define WIN_WID 800
# define WIN_HEI 500
# define MM_HEI 30
# define MM_WID 50
# define IMG_X 32
# define IMG_Y 32

/*DEFINE CHAR */
# define BYE "*********************\n* Good Bye ヾ(☆▽☆ ) *\n*********************\n"
# define IS_SPACE " \n\t\v\f\r"
# define IS_PLAYER "NSWE"
# ifndef IS_MAP
#  define IS_MAP "01NSWE"
# endif

# define SMP 5
# define SPD 0.1
# define RSP degree_to_radian(1)

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
# define ERR_KEY "Misclick ? Touche non valide\n"
# define ERR_WIN "> No window here...sooooo dark\n"

/* ACTIONS MESSAGES */
# define M_MSG "Inclure le message voulu ici"

/* STRUCT */

typedef struct s_map
{
	char	*map;
	char	**tabmap;
	int		nb_lines;
	int		len_line;
	int		hei;
	int		wid;
	int		mmap_size;
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
	int		size_tile;
}		t_map;

typedef struct s_vect
{
	float	a;
	int		x;
	int		y;
}	t_vect;

typedef struct s_player
{
	t_vect		pos;
	char		dir;
	float		distx;
	float		disty;
	float		dirx;
	float		diry;
	long double	x;
	long double	y;
	long double	angle;
//	float	a; //angle
	char		cardi;
	int			vue;
	int			initiated;
	t_vect		old;
}	t_player;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*img;
	void		*win;
	void		*mm;
	char		*mlx_add;
	int			mlx_bpp;
	int			mlx_nd; //endian
	int			mlx_len;
	int			move;
	int			move_x;
	t_player	*play;
	t_map		*map;
	t_vect		*pos;
}	t_cub;

typedef struct s_ray
{
}	t_ray;

/* UTILS */
//void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title);

/* MANDATORY */
t_cub	*init_game(char **argv);
void	init_pos(t_cub *cub);
void	set_pos(t_cub *cub, double x, double y);
// void	init_player_pos(t_cub *cub, int x, int y, char *cardi);
void	init_player_pos(t_cub *cub);
void	player_pos(t_cub *cub);

void	critical_errors(char *str);
void	error_close(char *str);

int		read_map(t_cub *cub, char *file);
int		draw_mmap(t_cub *cub, int i, int j);

void	check_file(char *str);
void	parse_map(t_map *map, char **av);
char	*ft_strjoin_cub(char *s1, char *s2, int mode);
int		ft_isspace(int c);
int		ft_nbrlen(int n);
size_t	ft_strlen_c(char *str, char c);
char	*ft_strtrim_head(char *s1, char const *set);
void	check_tabmap(t_map *map);
int		get_elems(t_map *map);
int		is_map(char c);

int		color_map(t_cub *cub);
int		create_trgb(int t, int r, int g, int b);
void	put_rect(t_cub *cub, int x, int y, int color, int size);

int		a_little_bit( t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		move_your_body(int o_key, t_cub *cub);
int		in_key_s_hook(int o_key, t_cub *cub);
void	ft_camera_l(t_cub *cub);
void	ft_camera_r(t_cub *cub);
void	move_w_angle(t_cub *cub, float new_x, float new_y);
void	move_s_angle(t_cub *cub, float new_x, float new_y);
void	move_a_angle(t_cub *cub, float new_x, float new_y);
void	move_d_angle(t_cub *cub, float new_x, float new_y);
void	move_left_camera(t_cub *cub, float new_x, float new_y);
void	move_right_camera(t_cub *cub, float new_x, float new_y);

double	degree_to_radian(double degree);

void	free_cub(t_cub *cub);

//int	get_floor_or_ceiling(t_map *map, int i);

/* BONUS (ON Y CROIT) */

//MAIS BIEN SUR !!
int		not_main(void);

#endif
