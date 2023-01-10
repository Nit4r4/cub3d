/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:27:46 by creyt             #+#    #+#             */
/*   Updated: 2023/01/10 15:49:18 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_background(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREENHEIGHT)
	{
		j = 0;
		while (j < SCREENWIDTH)
		{
			if (i < SCREENHEIGHT / 2 - cub->play.vue)
				my_mlx_pixel_put(cub->mlx, j, i, cub->map->ceiling);
			else
				my_mlx_pixel_put(cub->mlx, j, i, cub->map->floor);
			j++;
		}
		i++;
	}
}

void	where_is_the_player(t_cub *cub)
{
	put_rectangle(cub->map->tile_draw_size * 7,
		cub->map->tile_draw_size * 7, cub, make_trgb(50, 6, 92, 204));
}

void	process_image(t_cub *cub)
{
	put_background(cub);
	get_all_rays(cub);
	display_rays(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win,
		cub->img, 0, 0);
	if (cub->is_minimap)
	{
		put_grid2(cub);
		display_player(cub);
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win,
		cub->img, 0, 0);
}

int	loop_img(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->win);
	process_image(cub);
	return (0);
}
