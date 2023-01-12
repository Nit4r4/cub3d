/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 11:01:46 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		critical_errors(ERR_ARG);
	cub = init_game(cub);
	// cub->pos.x = (1 * CUBE) + (CUBE / 2);
	// cub->pos.y = (3 * CUBE) + (CUBE / 2);
	// cub->pos.a = 90;
	cub->win = mlx_new_window(cub->mlx_ptr, WIN_WID, WIN_HEI, "cub3D");
//	cub->img = mlx_new_image(cub->mlx_ptr, WIN_WID, WIN_HEI);
//	cub->mlx_add = mlx_get_data_addr(cub->img, &cub->mlx_bpp, &cub->mlx_len, &cub->mlx_nd);
	mlx_loop_hook(cub->mlx_ptr, loop_hook, cub);
	mlx_hook(cub->win, 2, 1L << 0, move_your_body, cub);
	mlx_hook(cub->win, RED_CROSS, 1L << 2, bouge_ton_bool, cub);
	//mlx_key_hook(cub->win, in_key_s_hook, cub);
//	mlx_loop_hook(cub->mlx_ptr, color_map, cub);
//	cub->mm = mlx_new_image(cub->mlx_ptr, MM_WID, MM_HEI);
	//mlx_loop_hook(cub->mlx_ptr, draw_mmap, cub);
	mlx_loop(cub->mlx_ptr);
	free(cub);
	return (0);
}
