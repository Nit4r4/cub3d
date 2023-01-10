/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:45:22 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/22 16:38:56 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_w_angle(t_cub *cub, float new_x, float new_y)
{
	new_x = cub->pos.x;
	new_y = cub->pos.y;
	cub->pos.x -= cub->play.distx * sin(cub->pos.a) * SPD;
	cub->pos.y -= cub->play.disty * cos(cub->pos.a) * SPD;
	// cub->pos.x += cub->play.distx * SPD;
	// cub->pos.y += cub->play.disty * SPD;
	// cub->pos.x = new_x;
	// cub->pos.y = new_y;
}

void	move_s_angle(t_cub *cub, float new_x, float new_y)
{
	new_x = cub->pos.x;
	new_y = cub->pos.y;
	cub->pos.x += cub->play.distx * sin(cub->pos.a) * SPD;
	cub->pos.y += cub->play.disty * cos(cub->pos.a) * SPD;
}

void	move_a_angle(t_cub *cub, float new_x, float new_y)
{
	new_x = cub->pos.x;
	new_y = cub->pos.y;
	cub->pos.x += cub->play.distx * sin(cub->pos.a) * SPD;
	cub->pos.y += cub->play.disty * cos(cub->pos.a) * SPD;
}

void	move_d_angle(t_cub *cub, float new_x, float new_y)
{
	new_x = cub->pos.x;
	new_y = cub->pos.y;
	cub->pos.x += cub->play.distx * sin(cub->pos.a) * SPD;
	cub->pos.y -= cub->play.disty * cos(cub->pos.a) * SPD;
}
