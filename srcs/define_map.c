/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:08:43 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/10 11:43:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_walls(t_cub *cub, int x_wall, int y_wall)
{
	if (cub->map.tabmap[(int)floor(y_wall / cub->map.size_tile)]
		[(int)floor(x_wall / cub->map.size_tile)] != '1')
	{
		cub->pos.x = cub->play.dirx;
		cub->pos.y = cub->play.diry;
	}
}

// void	update_position(int o_key, t_cub *cub) --> EN DUR AVEC SPD, BESOIN ? PAS SUR....
// {
// 	float	speed;

// 	speed = (int)cub->map.size_tile / 7;
// 	move_your_body(o_key, cub);
// }