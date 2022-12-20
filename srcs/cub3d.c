/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/20 18:02:18 by vferraro         ###   ########.fr       */
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

void	draw_line(int x2, int y2, t_cub *cub, int color)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - cub->pos.x;
	delta_y = (double)y2 - cub->pos.y - 20;
	delta_y = sin(cub->pos.pos) * 5;
	delta_x = cos(cub->pos.pos) * 5;
	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
	pixel_x = cub->pos.x;
	pixel_y = cub->pos.y;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(cub, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx_add + (y * cub->mlx_len + x * (cub->mlx_bpp / 8));
	*(unsigned int*)dst = color;
}

int	a_little_bit( t_cub *cub)
{
	t_vect	pos;
	int		color;

	pos.x = cub->pos.x;
	pos.y = cub->pos.y;
	color = create_trgb(0 , 200, 50, 50);
	// pos.y = (cub->map.hei)/2;
	// pos.x = (cub->map.wid)/2;

	my_mlx_pixel_put(cub, pos.x, pos.y, color);
	// my_mlx_pixel_put(cub, pos.x - 1, pos.y, color);
	// my_mlx_pixel_put(cub, pos.x - 2, pos.y, color);
	// my_mlx_pixel_put(cub, pos.x + 1, pos.y, color);
	// my_mlx_pixel_put(cub, pos.x + 2, pos.y, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 1, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 2, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 3, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 4, color);
	draw_line(pos.x, pos.y, cub, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 1, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 2, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 3, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 4, BLOOD);
	// mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}

int	move_your_body(int o_key, t_cub *cub)
{
	t_vect	pos;

	pos.x = cub->pos.x;
	pos.y = cub->pos.y;
	// int	pix;
	// pix = 0;
	// cub->move = 399;
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
		// if (cub->map.tabmap[pos.y][pos.x - 1] == '0')
		// {
		// 	cub->map.tabmap[pos.y][pos.x - 1] = 'N';
		// 	cub->map.tabmap[pos.y][pos.x] = '0';
		// }

		// cub->pos.x -= 5;
		cub->pos.pos -= 1;
		if (cub->pos.pos < 0)
			cub->pos.pos = 360;
		
		// cub->move--;
		
		// my_mlx_pixel_put(cub, pos.x, cub->move, BLOOD);
		// mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, WIN_HEI, WIN_WID);
	}
	else if (o_key == KEY_W)
		cub->pos.y -= 5;
	else if (o_key == KEY_S)
		cub->pos.y += 5;
	else if (o_key == KEY_D)
	{
		// cub->pos.x += 5;
		cub->pos.pos += 1;
		if (cub->pos.pos > 360)
			cub->pos.pos = 0;
	}
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
	//definir position du player
	cub->pos.x = 26 * 20 + 10;
	cub->pos.y = 11 * 20 + 10;
	cub->pos.pos = 90; //angle il faut changer le nom
	
	//draw_mmap(cub, 10, 20);
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, WIN_WID, WIN_HEI);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub);
	cub->mm = mlx_new_image(cub->mlx_ptr, MM_WID, MM_HEI);
	//mlx_loop_hook(cub->mlx_ptr, draw_mmap, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}