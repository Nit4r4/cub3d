/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/29 16:50:38 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	not_main(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, 800, 500);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp,
			&cub->mlx_len, &cub->mlx_nd);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (argc != 2)
		critical_errors(ERR_ARG);
	parse_map(&cub->map, argv);
	cub->pos->x = 26 * 20 + 10;
	cub->pos->y = 11 * 20 + 10;
	cub->pos->pos = 90; //angle il faut changer le nom
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, WIN_WID, WIN_HEI);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp,
			&cub->mlx_len, &cub->mlx_nd);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub);
	cub->mm = mlx_new_image(cub->mlx_ptr, MM_WID, MM_HEI);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
*/
int	main(int argc, char **argv)
{
	t_cub	*cub;

//	cub = malloc(sizeof(t_cub));
	if (argc != 2)
		critical_errors(ERR_ARG);
	cub = init_game(argv);
//	parse_map(cub->map, argv);
	//init_player_pos(cub);
	//definir position du player
	cub->pos->x = 26 * 20 + 10;
	cub->pos->y = 11 * 20 + 10;
	cub->pos->a = 90;
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
	free_cub(cub);
	return (0);
}
