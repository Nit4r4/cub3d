/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:48 by creyt             #+#    #+#             */
/*   Updated: 2022/12/22 10:24:04 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_your_body(int o_key, t_cub *cub)
{
	t_vect	pos;

	pos.x = cub->pos.x;
	pos.y = cub->pos.y;
	if (o_key == ESC)
	{
		ft_printf(BYE);
		exit(EXIT_FAILURE);
	}
	if (o_key == KEY_A)
		cub->pos.x -= 5;
	else if (o_key == ARROW_L)
	{
		cub->pos.pos -= 1;
		if (cub->pos.pos < 0)
			cub->pos.pos = 360;
	}
	else if (o_key == KEY_W)
		cub->pos.y -= 5;
	else if (o_key == KEY_S)
		cub->pos.y += 5;
	else if (o_key == KEY_D)
		cub->pos.x += 5;
	else if (o_key == ARROW_R)
	{
		cub->pos.pos += 1;
		if (cub->pos.pos > 360)
			cub->pos.pos = 0;
	}
	else if (o_key != KEY_A || o_key != KEY_S || \
				o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}

int	in_key_s_hook(int o_key, t_cub *cub)
{
	(void)o_key;
	mlx_key_hook(cub->win, a_little_bit, cub);
	return (0);
}

// int	ft_camera(t_cub *cub, int o_key)
// {
// 	if (o_key == ARROW_L)

// 	if (o_key == ARROW_R)
// }
