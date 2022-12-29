/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:48 by creyt             #+#    #+#             */
/*   Updated: 2022/12/29 14:54:21 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_your_body(int o_key, t_cub *cub)
{
	t_vect	pos;
	int	new_x;
	int	new_y;

	new_x = 0;
	new_y = 0;
	pos.x = cub->pos->x;
	pos.y = cub->pos->y;
	if (o_key == ESC)
		{
		ft_printf(BYE);
		exit(EXIT_FAILURE);
		}
	if (o_key == KEY_A)
		//cub->pos->x -= 5;
		move_a_angle(cub, new_x, new_y);
	else if (o_key == KEY_W)
		//cub->pos->y -= 5;
		move_w_angle(cub, new_x, new_y);
	else if (o_key == KEY_S)
		// cub->pos->y += 5;
		move_s_angle(cub, new_x, new_y);
	else if (o_key == KEY_D)
		//cub->pos->x += 5;
		move_d_angle(cub, new_x, new_y);
	else if (o_key == ARROW_L)
		{
		//move_left_camera(cub, new_x, new_y);
		// cub->pos->a -= 1;
		// if (cub->pos->a < 0)
		// 	cub->pos->a = 360;
		ft_camera_l(cub);
		}
	else if (o_key == ARROW_R)
	{
		//move_right_camera(cub, new_x, new_y);
		ft_camera_r(cub);

		// cub->pos->a += 1;
		// if (cub->pos->a > 360)
		// 	cub->pos->a = 0;
		// ft_camera(cub, o_key);
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


/*TEST CALCULS ANGLE PI*/
void	ft_camera_r(t_cub *cub)
{
	cub->pos->a += 0.1;
	if (cub->pos->a == 360. * (M_PI / 180))
		cub->pos->a = 0.;
	if (cub->pos->a > 360. * (M_PI / 180))
		cub->pos->a = 0. + (cub->pos->a - 2 * M_PI);
}

void	ft_camera_l(t_cub *cub)
{
	cub->pos->a -= 0.1;
	if (cub->pos->a == 0.)
		cub->pos->a = 360. * (M_PI / 180);
	if (cub->pos->a < 0.)
		cub->pos->a = 2 * M_PI - (cub->pos->a * -1);
}
