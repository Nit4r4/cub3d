/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:20:57 by creyt             #+#    #+#             */
/*   Updated: 2022/12/22 15:48:17 by creyt            ###   ########.fr       */
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
