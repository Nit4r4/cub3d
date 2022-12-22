/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:13:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/22 14:00:52 by vferraro         ###   ########.fr       */
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
		// cub->pos.a -= 1;
		// if (cub->pos.a < 0)
		// 	cub->pos.a = 360;
		// ft_camera(cub, o_key);
		}
	else if (o_key == KEY_W)
		//cub->pos.y -= 5;
		move_w_angle(cub, new_x, new_y);
	else if (o_key == KEY_S)
		cub->pos.y += 5;
	else if (o_key == KEY_D)
		cub->pos.x += 5;
	else if (o_key == ARROW_R)
	{
		// cub->pos.a += 1;
		// if (cub->pos.a > 360)
		// 	cub->pos.a = 0;
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

void	move_w_angle(t_cub *cub, float new_x, float new_y)
{
	new_x = cub->pos.x;
	new_y = cub->pos.y;
	cub->pos.x += cub->play.dist_x * sin(cub->pos.a) * SPD;
	cub->pos.y += cub->play.dist_y * cos(cub->pos.a) * SPD;
	// cub->pos.x += cub->play.dist_x * SPD;
	// cub->pos.y += cub->play.dist_y * SPD;
// 	cub->pos.x = new_x;
// 	cub->pos.y = new_y;
}

/*TEST CALCULS ANGLE PI*/
// void	ft_camera(t_cub *cub, int o_key)
// {
// 	if (o_key == ARROW_L)
// 	{
// 		cub->pos.a += 0.1;
// 		if (cub->pos.a == 360. * (M_PI / 180))
// 			cub->pos.a = 0.;
// 		if (cub->pos.a > 360. * (M_PI / 180))
// 			cub->pos.a = 0. + (cub->pos.a - 2 * M_PI);
// 	}
// 	if (o_key == ARROW_R)
// 	{
// 		cub->pos.a -= 0.1;
// 		if (cub->pos.a == 0.)
// 			cub->pos.a = 360. * (M_PI / 180);
// 		if (cub->pos.a < 0.)
// 			cub->pos.a = 2 * M_PI - (cub->pos.a * -1);
// 	}
// }