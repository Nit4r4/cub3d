/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:13:43 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 11:51:26 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* close the window */
int	bouge_ton_bool(void)
{
	ft_printf(BYE);
	exit(EXIT_FAILURE);
}

void	ft_tmp_angle(t_cub *cub)
{
	float	tmp_angle;
	int		x_wall;
	int		y_wall;

	tmp_angle = cub->pos->a;
	tmp_angle *= (M_PI / 180.0);
	cub->play->dirx = cub->pos->x + roundf(cos(tmp_angle) * SPD);
	cub->play->diry = cub->pos->y - roundf(sin(tmp_angle) * SPD);
	x_wall = cub->pos->x + (int)((float)cos((double)tmp_angle) * (SPD * 3.8));
	y_wall = cub->pos->y - (int)((float)sin((double)tmp_angle) * (SPD * 3.8));
}

int	move_your_body(int o_key, t_cub *cub)
{
	int		direction;
	int		x_wall;
	int		y_wall;

	direction = 1;
	x_wall = 0;
	y_wall = 0;
	in_key_s_hook(o_key, cub);
	if (o_key == ARROW_L)
	{
		ft_camera_l(cub);
		direction = 0;
	}
	else if (o_key == ARROW_R)
	{
		ft_camera_r(cub);
		direction = 0;
	}
	if (direction == 0)
		return (0);
	ft_tmp_angle(cub);
	check_walls(cub, x_wall, y_wall);
	return (0);
}

int	in_key_s_hook(int o_key, t_cub *cub)
{
	float	tmp_angle;
	int		direction;

	direction = 1;
	tmp_angle = cub->pos->a;
	if (o_key == ESC)
		bouge_ton_bool();
	if (o_key == KEY_A)
		tmp_angle = (int)(cub->pos->a + 90);
	else if (o_key == KEY_W)
		tmp_angle = cub->pos->a;
	else if (o_key == KEY_S)
		tmp_angle = (int)(cub->pos->a + 180);
	else if (o_key == KEY_D)
		tmp_angle = (int)(cub->pos->a - 90);
	else if (o_key != KEY_A || o_key != KEY_S
		|| o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}

/*TEST CALCULS ANGLE PI*/
