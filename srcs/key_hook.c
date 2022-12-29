/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:13:43 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/29 17:09:36 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_your_body(int o_key, t_cub *cub)
{
	float	tmp_angle;
	int		direction;

	direction = 1;
	tmp_angle = cub->pos.a;
	if (o_key == ESC)
	{
		ft_printf(BYE);
		exit(EXIT_FAILURE);
	}
	if (o_key == KEY_A)
		tmp_angle = (int)(cub->pos.a + 90);
	else if (o_key == KEY_W)
		tmp_angle = cub->pos.a;
	else if (o_key == KEY_S)
		tmp_angle = (int)(cub->pos.a + 180);
	else if (o_key == KEY_D)
		tmp_angle = (int)(cub->pos.a - 90);
	else if (o_key == ARROW_L)
	{
		ft_camera_l(cub);
		direction = 0;
	}
	else if (o_key == ARROW_R)
	{
		ft_camera_r(cub);
		direction = 0;
	}
	else if (o_key != KEY_A || o_key != KEY_S || \
				o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	if (direction == 0)
		return (0);
	tmp_angle *= (M_PI / 180.0);
	cub->pos.x = cub->pos.x + roundf(cos(tmp_angle) * SPD);
	cub->pos.y = cub->pos.y - roundf(sin(tmp_angle) * SPD);
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
	cub->pos.a -= SPD;
	if (cub->pos.a <= 0.)
		cub->pos.a = 360.;
}

void	ft_camera_l(t_cub *cub)
{
	cub->pos.a += SPD;
	if (cub->pos.a >= 360.)
		cub->pos.a = 0.;
}