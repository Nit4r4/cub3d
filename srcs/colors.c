/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:02:15 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 11:37:18 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_rect(t_cub *cub, int x, int y, int color, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			my_mlx_pixel_put(cub, x * size + i, y * size + j, color);
			i++;
		}
		j++;
	}
}

int	color_map(t_cub *cub)
{
	int	x;
	int	y;
	int	size;

	size = CUBE;
	y = 0;
	if (cub->win)
	{
		y = 0;
		while (y < cub->map->nb_lines)
		{
			x = 0;
			while (x < cub->map->len_line)
			{
				if (cub->map->tabmap[y][x] == '1')
					put_rect(cub, x, y, BLOOD, size);
				else if (cub->map->tabmap[y][x] == '0')
					put_rect(cub, x, y, GREY, size);
				else if (cub->map->tabmap[y][x] == 'N')
					put_rect(cub, x, y, GREY, size);
				else
					put_rect(cub, x, y, WHITE, size);
				x++;
			}
			y++;
		}
		a_little_bit(cub);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	}
	else
	{
		free(cub->win);
		critical_errors(ERR_WIN);
	}
	return (0);
}