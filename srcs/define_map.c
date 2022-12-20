/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:08:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/20 17:19:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int	color_map(t_cub *cub)
// {
// 	size_t	i;
// 	size_t	j;
	
// 	j = 0;
// 	if (cub->win)
// 	{
// 		while (j < WIN_HEI)
// 		{
// 			i = 0;
// 			while (i < WIN_WID)
// 			{
// 				if (i % 50 == 0 || j % 50 == 0)
// 					my_mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, WHITE);
// 				else
// 				{
// 					if ((i > 50 && j < 450) && (j > 50 && i < 750))
// 						my_mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, GREY);
// 					else
// 						my_mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, BLACK);
// 				}
// 				i++;
// 			}
// 			j++;
// 		}
// 		a_little_bit(cub);
// 	}
// 	else
// 	{
// 		free(cub->win);
// 		critical_errors(ERR_WIN);
// 	}
// 	return (0);
// }

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

	size = 20;
	y = 0;
	if (cub->win)
	{
		// while (y < WIN_HEI)
		// {
		// 	x = 0;
		// 	while (x < WIN_WID)
		// 	{
		// 		// AFFICHER FOND D ECRAN
		// 		my_mlx_pixel_put(cub, x, y, WHITE);
		// 		// draw_mmap(cub, i, j);
		// 		x++;
		// 	}
		// 	y++;
		// }
		// mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 0, 0);
		// printf("wid[%d]height[%d]\n", cub->map.len_line, cub->map.nb_lines);
		y = 0;
		// printf("N=%c\n", cub->map.tabmap[11][26]);
		while (y < cub->map.nb_lines)
		{
			x = 0;
			while (x < cub->map.len_line)
			{
				// printf("x[%d]y[%d]\n", x, y);
				if (cub->map.tabmap[y][x] == '1')
					put_rect(cub, x, y, BLOOD, size);
				else if (cub->map.tabmap[y][x] == '0')
					put_rect(cub, x, y, GREY, size);
				else if (cub->map.tabmap[y][x] == 'N')
					put_rect(cub, x, y, GREY, size);
				else
					put_rect(cub, x, y, WHITE, size);
				x++;
			}
			y++;
		}
		// put_rect(cub, 0, 0, BLOOD, 128);
		// put_rect(cub, 1, 1, BLOOD, 128);
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


// void	read_mmap(t_cub *cub, int x, int y)
// {
// 	char *read = NULL;

// 		if (read == "0")
// 			my_mlx_pixel_put(cub->mlx_ptr, cub->win, x, y, GREY);
// 		if (read == "1")
// 			my_mlx_pixel_put(cub->mlx_ptr, cub->win, x, y, BLOOD);
// 	}
// }

// int	draw_mmap(t_cub *cub, int i, int j)
// {
// //	char	*read = NULL;
// 	int	x = 0;
// 	int	y = 0;

// 	// while (cub->map.tabmap[y][x])
// 	// {
// 		y = 0;
// 		while (y < 30)
// 		{
// 			x = 0;
// 			while (x < 30)
// 			{
// 				// read_mmp(cub, x, y);
// 				if (cub->map.tabmap[y][x] == 0)
// 					my_mlx_pixel_put(cub, x, y, GREY);
// 				else if (cub->map.tabmap[y][x] == 1)
// 					my_mlx_pixel_put(cub, x, y, BLOOD);
// 				x++;
// 			}
// 			y++;
// 		}
// 	// }
// 	return (0);
// }

// int	draw_mmap(t_cub *cub, int i, int j)
// {
// 	//char	read;
// 	int	x = 0;
// 	int	y = 0;
	
// 	while (cub->map.tabmap[y][x])
// 	{
// 		j = 0;
// 		while (j < WIN_HEI)
// 		{
// 			if (cub->map.tabmap[y][x] == 0)
// 				my_mlx_pixel_put(cub->mlx_ptr, cub->win, i * 10, j * 10, WHITE);
// 			if (cub->map.tabmap[y][x] == 1)
// 				my_mlx_pixel_put(cub->mlx_ptr, cub->win, i * 10, j * 10, BLACK);
// 		}
// 		j++;

// 		i = 0;
// 		while (i < WIN_HEI)
// 		{
// 			if (cub->map.tabmap[y][x] == 0)
// 				my_mlx_pixel_put(cub->mlx_ptr, cub->win, i * 10, j * 10, WHITE);
// 			if (cub->map.tabmap[y][x] == 1)
// 				my_mlx_pixel_put(cub->mlx_ptr, cub->win, i * 10, j * 10, BLACK);
// 		}
// 		i++;
// 	}
// 	return (0);
// }