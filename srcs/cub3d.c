/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/15 15:44:34 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
// int	main(int argc, char **argv)
// {
// 	t_cub	cub;

// 	if (argc >= 2)
// 	{
// 		printf("%d\n", read_map(&cub, argv[2]));
// 	}
// }


//RE LIRE LES MAN DE MLX

int	a_little_bit( t_cub *cub)
{
	t_vect	pos;
	pos.x = 400;
	pos.y = 250;
	// pos.y = (cub->map.hei)/2;
	// pos.x = (cub->map.wid)/2;

	mlx_pixel_put(cub->mlx_ptr, cub->win, pos.x, pos.y, BLOOD);
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
	// int	pix;
	// pix = 0;
	cub->move = 399;
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
		mlx_pixel_put(cub->mlx_ptr, cub->win, pos.x, cub->move, BLOOD);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, WIN_HEI, WIN_WID);
	}
	else if (o_key == KEY_W)
		printf("%d\n", o_key);
	else if (o_key == KEY_S)
		printf("%d\n", o_key);
	else if (o_key == KEY_D)
		printf("%d\n", o_key);
	else if (o_key != KEY_A || o_key != KEY_S || \
				o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}

int	in_key_s_hook(int o_key, t_cub *cub)
{
	(void)o_key;
	mlx_key_hook(cub->win, a_little_bit, cub);
	return (0);
}

int	not_main(void)
{
	//void	*mlx_ptr;
	//void	*win;
	//int		perso = 0;
	t_cub	*cub;
	//int		o_key = 0;
	//void	*img;

	//cub->map.map_size = init_pos(cub);
	cub = malloc(sizeof(t_cub));
	//cub->move = 399;
	//erreur_args(argc, argv);
	//init(cub);
	// if (init_asset(argv[1], scene) == 1)
	// 	asset_is_valid(&scene->asset);
	// else
	// 	return(0);

	//mlx_ptr = NULL;
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, 800, 500);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);


	//a_little_bit(mlx_ptr, win);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub); //soucis de memoire et de exe speed
	//mlx_clear_window(cub->mlx_ptr, cub->win);
	//mlx_put_image_to_window(mlx_ptr, win, cub->img, 800, 500);
	//mlx_key_hook(win, in_key_s_hook, cub);
	//in_key_s_hook(game);
	//move_your_body(mlx_ptr, win, perso);
	mlx_loop(cub->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (argc != 2)
		critical_errors(ERR_ARG);
	parse_map(&cub->map, argv);
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, 800, 500);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub); //soucis de memoire et de exe speed
	mlx_loop(cub->mlx_ptr);
	return (0);
}