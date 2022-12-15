/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:08:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/15 11:30:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	color_map(t_cub *cub)
{
	size_t i = 0;
	size_t	j = 0;
	
	if (cub->win)
	{
		while (j < WIN_WID)
		{
			while (i < WIN_HEI)
			{
				if (i % 50 == 0 || j % 50 == 0)
					mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0XFFFFFF);
				else
				{
					if ((i > 50 && j < 450) && (j > 50 && i < 750))
						mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0Xcecece);
					else
						mlx_pixel_put(cub->mlx_ptr, cub->win, i, j, 0X000000);
				}
				i++;
			}
			j++;
		}
		a_little_bit(cub);
	}
	else
		{
		free(cub->win);
		critical_errors(ERR_WIN);
		}
	return (0);
}