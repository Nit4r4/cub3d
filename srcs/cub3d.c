/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/08 14:32:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* close the window */
int	bouge_ton_bool(void)
{
	exit(0);
}

// void	map(int x, int y)
// {
// 	11111111111
// 	10001000001
// 	10001001001
// 	10001001001
// 	10001001001
// 	10001001001
// 	10000000001
// 	11111111111;
// }

// int	define_map(t_cub *cub, int	x, int	y)
// {
	
// 	if (x % 50 == 0 || y % 50 == 0)
// 		mlx_pixel_put(cub->mlx_ptr, cub->win, x, y, 0XFFFFFF);
// 	else
// 	{
// 	if ((x > 50 && y < 450) && (y > 50 && x < 750))
// 		mlx_pixel_put(cub->mlx_ptr, cub->win, x, y, 0Xcecece);
// 	else
// 		mlx_pixel_put(cub->mlx_ptr, cub->win, x, y, 0X000000);
// 	}
// 	return(0);
// }


int	color_map(t_cub *cub)
{
	if (cub->win)
	{
		size_t	j = 0;
		for (; j < 500; j++)
		{
			for (size_t i = 0; i < 800; i++)
			{
				if (i % 50 == 0 || j % 50 == 0)
					mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0XFFFFFF);
				else
				{
					if ((i > 50 && j < 450) && (j > 50 && i < 750))
						mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0Xcecece);
					else
						mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0X000000);
				}
			}
		}
		a_little_bit(cub);
	}
	else
		{
		free(cub->win);
		critical_errors(ERR_WIN);
		}
	return (0);
}

// int	size_map(t_cub *cub)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < cub->map.hei)
// 	{
// 		x = 0;
// 		while (x < cub->map.wid)
// 		{
// 			color_map(cub);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return(0);
// }


// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
int	a_little_bit( t_cub *cub)
{	
	t_vect	pos;
	// pos.x = 400;
	// pos.y = 250;
	pos.y = (cub->map.hei)/2;
	pos.x = (cub->map.wid)/2;

	mlx_pixel_put(cub->mlx_ptr, cub->win, pos.x, pos.y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x + 1, cal_y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x + 2, cal_y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x + 3, cal_y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x + 4, cal_y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x + 5, cal_y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x, cal_y + 1, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x, cal_y + 2, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x, cal_y + 3, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, cal_x, cal_y + 4, 0X7E0EF4);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 800, 500);
	//mlx_pixel_put(cub->mlx_ptr, win, 200, 250, 0X7E0EF4);
	return (0);
}

int	move_your_body(int o_key, t_cub *cub)
{
	t_vect	pos;
	// int	o_key = 0;
	// printf("%d\n", o_key);
	//perso = a_little_bit(mlx_ptr, win, cub);
	if (o_key == ESC)
		{
			ft_printf("*********************\n* Good Bye ヾ(☆▽☆ ) *\n*********************\n");
			exit(EXIT_FAILURE);
		}
	if (o_key == KEY_A)
	{
		cub->move--;
		mlx_pixel_put(cub->mlx_ptr, cub->win, cub->move, pos.y, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 398 - i, 250, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 399 - i, 250, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 250, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 402 - i, 250, 0Xcecece);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 401 - i, 250, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 250, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 249, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 248, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 247, 0X7E0EF4);
	// mlx_pixel_put(cub->mlx_ptr, cub->win, 400 - i, 246, 0X7E0EF4);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 800, 500);
	}
	else if (o_key == KEY_W)
		printf("%d\n", o_key);
	else if (o_key == KEY_S)
		printf("%d\n", o_key);
	else if (o_key == KEY_D)
		printf("%d\n", o_key);
	else if (o_key != KEY_A || o_key != KEY_S || o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}

int	in_key_s_hook(int o_key, t_cub *cub)
{
	// void	*mlx_ptr = NULL;
	//void *mlx_ptr = NULL;
	(void)o_key;
	// mlx_loop_hook(mlx_ptr, bouge_ton_bool, NULL);
	// mlx_loop_hook(mlx_ptr, move_your_body, NULL);
	// mlx_hook(win, 17, 0L << 0, bouge_ton_bool, cub);
	// mlx_hook(win, 53, 0L << 0, bouge_ton_bool, cub);
	// mlx_hook(win, 13, 1L << 0, move_your_body, cub);
	mlx_key_hook(cub->win, a_little_bit, cub);
	// mlx_hook(win, 1, 1L << 0, move_your_body, cub);
	// mlx_hook(win, 2, 1L << 0, move_your_body, cub);
	// mlx_hook(win, KEY_A, 1L << 0, move_your_body, cub);
	//mlx_loop_hook(mlx_ptr, move_your_body, NULL);
	return (0);
}

int	main(void)
{
	//void	*mlx_ptr;
	//void	*win;
	//int		perso = 0;
	t_cub	*cub;
	//int		o_key = 0;
	//void	*img;

	//cub->map.map_size = init_pos(cub);
	cub = malloc(sizeof(t_cub));
	cub->move = 397;
	//erreur_args(argc, argv);
	//init(cub);
	// if (init_asset(argv[1], scene) == 1)
	// 	asset_is_valid(&scene->asset);
	// else
	// 	return(0);

	//mlx_ptr = NULL;
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, 800, 500, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, 800, 500);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);


	//a_little_bit(mlx_ptr, win);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub); //soucis de memoire et de exe speed
	//mlx_put_image_to_window(mlx_ptr, win, cub->img, 800, 500);
	//mlx_key_hook(win, in_key_s_hook, cub);
	//in_key_s_hook(game);
	//move_your_body(mlx_ptr, win, perso);
	mlx_loop(cub->mlx_ptr);
}
