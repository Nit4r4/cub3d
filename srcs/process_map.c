/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:46:50 by creyt             #+#    #+#             */
/*   Updated: 2023/01/12 10:16:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_background(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEI)
	{
		j = 0;
		while (j < WIN_WID)
		{
			if (i < WIN_HEI / 2 - cub->play.vue)
				my_mlx_pixel_put(cub->mlx_ptr, j, i, cub->map.ceiling);
			else
				my_mlx_pixel_put(cub->mlx_ptr, j, i, cub->map.floor);
			j++;
		}
		i++;
	}
}

void	process_player(t_cub *cub)
{
	put_rectangle(cub->map.draw_tile * 7,
		cub->map.draw_tile * 7, cub, create_trgb(50, 6, 92, 204));
}

void	process_image(t_cub *cub)
{
	put_background(cub);
	get_all_rays(cub);
	display_rays(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win,
		cub->img, 0, 0);
	if (cub->minimap)
	{
		get_grid(cub);
		process_player(cub);
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win,
		cub->img, 0, 0);
}

int	loop_hook(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->win);
	process_image(cub);
	return (0);
}

void	check_walls(t_cub *cub, int x_wall, int y_wall)
{
	if (cub->map.tabmap[(int)floor(y_wall / cub->map.size_tile)]
		[(int)floor(x_wall / cub->map.size_tile)] != '1')
	{
		cub->pos.x = cub->play.dirx;
		cub->pos.y = cub->play.diry;
	}
}