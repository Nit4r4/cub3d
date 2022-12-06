/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/06 19:04:12 by vferraro         ###   ########.fr       */
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

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
int	a_little_bit(void *mlx_ptr, void *win)
{
	mlx_pixel_put(mlx_ptr, win, 398, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 399, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 401, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 402, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 249, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 248, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 247, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 246, 0X7E0EF4);
	//mlx_pixel_put(mlx_ptr, win, 200, 250, 0X7E0EF4);
	return (0);
}

int	move_your_body(void *mlx_ptr, void *win, int perso)
{
	int	o_key = 0;

	//perso = a_little_bit(mlx_ptr, win);

	if (o_key == ESC)
		EXIT_FAILURE;
	if (o_key == KEY_A)
		{
		mlx_pixel_put(mlx_ptr, win, 397, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 398, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 399, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 402, 250, 0Xcecece);
		mlx_pixel_put(mlx_ptr, win, 401, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 249, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 248, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 247, 0X7E0EF4);
		mlx_pixel_put(mlx_ptr, win, 400, 246, 0X7E0EF4);
		}
	else if (o_key == KEY_W)
		perso -= 1;
	else if (o_key == KEY_S)
		perso += 1;
	else if (o_key == KEY_D)
		perso += 1;
	else if (o_key != KEY_A || o_key != KEY_S \
			|| o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}

int	in_key_s_hook(int o_key, t_cub *cub)
{
	// void	*mlx_ptr = NULL;
	void	*win = NULL;
	//void *mlx_ptr = NULL;
	(void)o_key;

	// mlx_loop_hook(mlx_ptr, bouge_ton_bool, NULL);
	// mlx_loop_hook(mlx_ptr, move_your_body, NULL);
	mlx_hook(win, 17, 0L << 0, bouge_ton_bool, cub);
	mlx_hook(win, 53, 0L << 0, bouge_ton_bool, cub);
	mlx_hook(win, 13, 1L << 0, move_your_body, cub);
	//mlx_hook(win, 0, 1L << 0, move_your_body, cub);
	mlx_hook(win, 1, 1L << 0, move_your_body, cub);
	mlx_hook(win, 2, 1L << 0, move_your_body, cub);
	mlx_hook(win, KEY_A, 1L << 0, move_your_body, cub);
	//mlx_loop_hook(mlx_ptr, move_your_body, NULL);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win;
	//int		perso = 0;
	t_cub	*cub = NULL;
	//int		o_key = 0;

	mlx_ptr = NULL;
	mlx_ptr = mlx_init(mlx_ptr);
	win = mlx_new_window(mlx_ptr, 800, 500, "cub3D");

	size_t	j = 0;
	for (; j < 500; j++)
	{
		for (size_t i = 0; i < 800; i++)
		{
			if (i % 50 == 0 || j % 50 == 0)
			{	
				mlx_pixel_put(mlx_ptr, win, i, j, 0XFFFFFF);
			}
			else
			{
				if ((i > 50 && j < 450) && (j > 50 && i < 750))
				{
					mlx_pixel_put(mlx_ptr, win, i, j, 0Xcecece);
				}
				else
				{
					mlx_pixel_put(mlx_ptr, win, i, j, 0X000000);
				}
			}
		}
	}
	a_little_bit(mlx_ptr, win);
	mlx_key_hook(win, in_key_s_hook, &cub);
	//in_key_s_hook(game);
	//move_your_body(mlx_ptr, win, perso);
	mlx_loop(mlx_ptr);
}
