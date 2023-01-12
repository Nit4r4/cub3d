/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:48:41 by creyt             #+#    #+#             */
/*   Updated: 2023/01/12 10:05:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_grid(t_grid *grid, t_cub *cub)
{
	grid->size = cub->map.draw_tile;
	grid->p_x = floor(cub->pos.x / cub->map.size_tile);
	grid->p_y = floor(cub->pos.y / cub->map.size_tile);
	grid->i = grid->p_y - 5;
	grid->k = 0;
}

void	put_rectangle(int x, int y, t_cub *cub, int color)
{
	int	i;
	int	j;
	int	size;

	size = cub->map.draw_tile;
	i = y;
	while (i < size + y)
	{
		j = x;
		while (j < size + x)
		{
			my_mlx_pixel_put(cub, j, i, color);
			j++;
		}
		i++;
	}
}
void	put_rectangles(t_grid *grid, t_cub *cub)
{
	int	x;
	int	y;

	x = grid->l * grid->size + (cub->map.draw_tile * 2);
	y = grid->k * grid->size + (cub->map.draw_tile * 2);
	if (grid->i < 0 || grid->j < 0 || grid->i > cub->map.nb_lines - 1
		|| grid->j > cub->map.len_line - 1)
		;
	else if (cub->map.tabmap[grid->i][grid->j] == '1')
		put_rectangle(x, y, cub, create_trgb(50, 105, 105, 105));
	else if (cub->map.tabmap[grid->i][grid->j] == '0'
		|| ft_strchr("NWSE", cub->map.tabmap[grid->i][grid->j]))
		put_rectangle(x, y, cub, create_trgb(50, 180, 180, 180));
}

void	get_grid(t_cub *cub)
{
	t_grid	grid;

	init_grid(&grid, cub);
	while (grid.i < grid.p_y + 6)
	{
		grid.j = grid.p_x - 5;
		grid.l = 0;
		while (grid.j < grid.p_x + 6)
		{
			put_rectangles(&grid, cub);
			grid.j++;
			grid.l++;
		}
		grid.k++;
		grid.i++;
	}
}