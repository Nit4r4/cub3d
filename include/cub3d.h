/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:55 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 11:49:53 by creyt            ###   ########.fr       */
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

/* DEFINE SIZES */
# define WIN_WID 800
# define WIN_HEI 500
# define MM_HEI 30
# define MM_WID 50
# define IMG_X 32
# define IMG_Y 32
# define CUBE 64

/*DEFINE CHAR */
# define BYE "*********************\n* Good Bye ヾ(☆▽☆ ) *\n*********************\n"
# define IS_SPACE " \n\t\v\f\r"
# define IS_PLAYER "NSWE"
# ifndef IS_MAP
#  define IS_MAP "01NSWE"
# endif

/*DEFINE VALUES */
# define SMP 5
# define SPD 10
# define RSP degree_to_radian(1) //modifie

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
# define ERR_COLOR "Error\nWrong color\n"
# define ERR_MALLOC "Error\nCannot allocate memory\n"
# define ERR_MAP_CONTENT "Error\nInvalid content map\n"
# define ERR_MAP_SIZE "Error\nInvalid size map\n"
# define ERR_MAP_PLAYER "Error\nInvalid player map\n"
# define ERR_KEY "Misclick ? Touche non valide\n"
# define ERR_WIN "> No window here...sooooo dark\n"
# define ERR_TEX "Error\nTexture not found\n"

/* STRUCT */
typedef struct s_grid
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	p_x;
	int	p_y;
	int	size;
}	t_grid;

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
	int		draw_tile;
}		t_map;

typedef struct s_vect
{
	float	a;
	int		x;
	int		y;
}	t_vect;

typedef struct s_player
{
	t_vect	pos;
	int		init;
	char	dir;
	float	distx;
	float	disty;
	float	dirx;
	float	diry;
	char	cardi;
	int		vue;
	t_vect	old;
}	t_player;

typedef struct s_ray
{
	long double		x;
	long double		y;
	long double		delta;
	char			side;
	int				ver_hor;
	long double		relative_angle;
	float			angle;
}	t_ray;

typedef struct s_texture
{
	void	*tex;
	int		bits_nb;
	int		len_line;
	int		endien;
	int		*addr;
	int		wid_tex;
	int		hei_tex;
}	t_texture;

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
	int			nbr_t;
	int			minimap;
	t_player	*play;
	t_map		*map;
	t_vect		*pos;
	t_ray		*ray;
	t_texture	*tex;
}	t_cub;

/* MANDATORY */
/* init.c */
t_cub	*init_game(char **arv);
void	init_player(t_cub *cub);
void	init_player_pos(t_cub *cub);
int		init_texture(t_cub *cub);

/* parse_map.c */
void	get_tabmap(t_map *map, int i);
void	parse_map(t_map *map, char **av);

/* check_map.c */
void	critical_errors(char *str); // a changer de fichier ?
void	check_file(char *str);
int		colorfool(int color);
void	check_border_map(t_map *map, int x, int y);
void	check_center_map(t_map *map, int x, int y);
void	check_tabmap(t_map *map);

/* map_utils.c */
int		ft_isspace(int c);
int		get_floor_or_ceiling(t_map *map, int i);
int		get_elems(t_map *map);

/* colors.c */
int		color_map(t_cub *cub);
int		create_trgb(int t, int r, int g, int b);
void	put_rect(t_cub *cub, int x, int y, int color, int size);

/* play_directions.c
void	move_w_angle(t_cub *cub, float new_x, float new_y);
void	move_s_angle(t_cub *cub, float new_x, float new_y);
void	move_a_angle(t_cub *cub, float new_x, float new_y);
void	move_d_angle(t_cub *cub, float new_x, float new_y);
*/

/* its_alive.c */
void	draw_line(int x2, int y2, t_cub *cub, int color);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		my_mlx_pixel_get(t_texture *tex, int x, int y);
int		a_little_bit( t_cub *cub);

/* key_hook.c */
int		bouge_ton_bool(void);
int		move_your_body(int o_key, t_cub *cub);
int		in_key_s_hook(int o_key, t_cub *cub);
void	ft_tmp_angle(t_cub *cub);

/* cam_directions.c */
void	ft_camera_l(t_cub *cub);
void	ft_camera_r(t_cub *cub);

/* raycasting.c */
int		get_wall(int x, int y, t_cub *cub, t_ray *ray);
t_ray	*select_ray(t_cub *cub, float angle, t_ray *ray);
void	get_vertical_ray(t_cub *cub, t_ray *ray, float angle);
void	get_horizontal_ray(t_cub *cub, t_ray *ray, float angle);

/* raycasting2.c */
void	get_all_rays(t_cub *cub);
int		choose_image(t_cub *cub, t_ray *ray, int y, int size);
void	display_ray(t_cub *cub, int x, int j);
void	display_rays(t_cub *cub);

/* process_minimap.c */
void	init_grid(t_grid *grid, t_cub *cub);
void	put_rectangle(int x, int y, t_cub *cub, int color);
void	put_rectangles(t_grid *grid, t_cub *cub);
void	get_grid(t_cub *cub);

/*process_map.c */
void	check_walls(t_cub *cub, int x_wall, int y_wall);
int		loop_hook(t_cub *cub);

/* free.c */
void	free_tab(char **tab, int len);
void	free_map(t_map *map);
void	free_cub(t_cub *cub);

/* mini_libft.c */
char	*ft_strjoin_cub(char *s1, char *s2, int mode);
int		ft_nbrlen(int n);
size_t	ft_strlen_c(char *str, char c);
char	*ft_strtrim_head(char *s1, char const *set);
int		is_map(char c);

int		ft_abs(int x);
double	degree_to_radian(double degree);

/*
void	init_pos(t_cub *cub);
void	set_pos(t_cub *cub, double x, double y);
// void	init_player_pos(t_cub *cub, int x, int y, char *cardi);
int		read_map(t_cub *cub, char *file);
int		draw_mmap(t_cub *cub, int i, int j);
*/

/* BONUS (ON Y CROIT ou pas...) */

// RIP (hommage aux petites fonctions parties trop tot...)
void	error_close(char *str);
#endif
