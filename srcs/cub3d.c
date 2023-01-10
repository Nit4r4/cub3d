/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/10 13:58:20 by vferraro         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (argc != 2)
		critical_errors(ERR_ARG);
	parse_map(&cub->map, argv);
	init_game(cub);
	//init_player_pos(cub, cardi);
	//definir position du player selon la map 
	cub->pos.x = (1 * CUBE) + (CUBE / 2);
	cub->pos.y = (3 * CUBE) + (CUBE / 2);
	cub->pos.a = 90;
	//
	cub->mlx_ptr = mlx_init();
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
	cub->img = mlx_new_image(cub->mlx_ptr, WIN_WID, WIN_HEI);
	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_hook(cub->win, RED_CROSS, 1L << 2, bouge_ton_bool, cub);
	//mlx_key_hook(cub->win, in_key_s_hook, cub);
	mlx_loop_hook(cub->mlx_ptr, color_map, cub);
	cub->mm = mlx_new_image(cub->mlx_ptr, MM_WID, MM_HEI);
	//mlx_loop_hook(cub->mlx_ptr, draw_mmap, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}