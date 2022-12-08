/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/08 11:59:20 by vferraro         ###   ########.fr       */
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
	}
	else
		{
		free(cub->win);
		critical_errors(ERR_WIN);
		}
	return (0);
}

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
int	a_little_bit( t_cub *cub)
{	
	mlx_pixel_put(cub->mlx_ptr, cub->win, 398, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 399, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 401, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 402, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 249, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 248, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 247, 0X7E0EF4);
	mlx_pixel_put(cub->mlx_ptr, cub->win, 400, 246, 0X7E0EF4);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 800, 500);
	//mlx_pixel_put(cub->mlx_ptr, win, 200, 250, 0X7E0EF4);
	return (0);
}

int	move_your_body(int o_key, t_cub *cub)
{
	// int	o_key = 0;
	// printf("%d\n", o_key);
	//perso = a_little_bit(mlx_ptr, win, cub);
	if (o_key == ESC)
		{
			ft_printf("Good Bye\n");
			exit(EXIT_FAILURE);
		}
	if (o_key == KEY_A)
	{
		cub->test--;
		mlx_pixel_put(cub->mlx_ptr, cub->win, cub->test, 250, 0X7E0EF4);
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


	cub = malloc(sizeof(t_cub));
	cub->test = 397;
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
	mlx_loop_hook(cub->mlx_ptr, color_map, cub); //soucis de memoire et de exe speed
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	//mlx_put_image_to_window(mlx_ptr, win, cub->img, 800, 500);
	//mlx_key_hook(win, in_key_s_hook, cub);
	//in_key_s_hook(game);
	//move_your_body(mlx_ptr, win, perso);
	mlx_loop(cub->mlx_ptr);
}
