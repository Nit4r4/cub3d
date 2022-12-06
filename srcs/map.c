/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:47:50 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/06 13:08:30 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map.hei)
	{
		x = 0;
		while (x < cub->map.wid)
		{
			define_map(cub, x, y);
			x++;
		}
		y++;
	}
}
