/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_alive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:05:29 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/10 15:03:46 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_line(int x2, int y2, t_cub *cub, int color)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - cub->pos.x;
	delta_y = (double)y2 - cub->pos.y;
	delta_y = sin(cub->pos.a * (M_PI / 180.0)) * SMP;
	delta_x = cos(cub->pos.a * (M_PI / 180.0)) * SMP;
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

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if ((0 < x && x < WIN_WID) && (0 < y && y < WIN_HEI))
	{
	dst = cub->mlx_add + (y * cub->mlx_len + x * (cub->mlx_bpp / 8));
	*(unsigned int *)dst = color;
	}
}

int	my_mlx_pixel_get(t_texture *tex, int x, int y)
{
	unsigned int	color;

	color = 0;
	if ((0 <= x && x <= tex->wid_tex) && (0 <= y && y <= tex->hei_tex))
	{
		color = tex->addr[y * tex->len_line / 4 + x];
	}
	return (color);
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

	my_mlx_pixel_put(cub, pos.x - 1, pos.y, color);
	my_mlx_pixel_put(cub, pos.x - 2, pos.y, color);
	my_mlx_pixel_put(cub, pos.x + 1, pos.y, color);
	my_mlx_pixel_put(cub, pos.x + 2, pos.y, color);
	my_mlx_pixel_put(cub, pos.x, pos.y - 1, color);
	my_mlx_pixel_put(cub, pos.x, pos.y - 2, color);
	my_mlx_pixel_put(cub, pos.x, pos.y + 1, color);
	my_mlx_pixel_put(cub, pos.x, pos.y + 2, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 1, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 2, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 3, color);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 4, color);
	// draw_line(pos.x, pos.y + 100, cub, BLOOD);
	// put_rect(cub, pos.x, pos.y, BLOOD, 100);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 1, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 2, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 3, BLOOD);
	// my_mlx_pixel_put(cub, pos.x, pos.y - 4, BLOOD);
	// mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
	return (0);
}

