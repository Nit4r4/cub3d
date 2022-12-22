/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:21:15 by creyt             #+#    #+#             */
/*   Updated: 2022/12/22 10:23:07 by creyt            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (argc != 2)
		critical_errors(ERR_ARG);
	parse_map(&cub->map, argv);
	cub->pos.x = 26 * 20 + 10;
	cub->pos.y = 11 * 20 + 10;
	cub->pos.pos = 90; //angle il faut changer le nom
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
