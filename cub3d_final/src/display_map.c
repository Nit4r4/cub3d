/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:02:56 by creyt             #+#    #+#             */
/*   Updated: 2023/01/13 09:03:43 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_loop_hook(t_data	*data)
{
	mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
	update_image(data);
	//data->frame = (data->frame + 1) % 1000000000;
	return (0);
}

void	update_image(t_data *data)
{
	put_background(data);
	get_all_rays(data);
	display_rays(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
	if (data->is_minimap)
	{
		put_grid2(data);
		display_player(data);
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
}

void	display_player(t_data *data)
{
	put_rectangle(data->map->tile_draw_size * 7,
		data->map->tile_draw_size * 7, data, make_trgb(50, 6, 92, 204));
}

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREENHEIGHT)
	{
		j = 0;
		while (j < SCREENWIDTH)
		{
			if (i < SCREENHEIGHT / 2 - data->pov_y)
				my_mlx_pixel_put(data->mlx, j, i, data->map->ceiling);
			else
				my_mlx_pixel_put(data->mlx, j, i, data->map->floor);
			j++;
		}
		i++;
	}
}
