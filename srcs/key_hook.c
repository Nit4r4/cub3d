/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:48 by creyt             #+#    #+#             */
/*   Updated: 2022/12/20 11:22:24 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_window(t_cub *cub)
{
	if (cub)
		exit (0);
	return (0);
}

int	key_hook(t_cub *cub)
{
	mlx_hook(cub->win, 17, 0L << 0, exit_window, cub);
	//mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	return (0);
}

/* gere les mouvements */
int	move_your_body(int o_key, t_cub *cub)
{
	t_vect	pos;

	if (o_key == ESC)
	{
		ft_printf(BYE);
		exit_window(cub);
	}
	if (o_key == KEY_A)
	{
		cub->move--;
		mlx_pixel_put(cub->mlx_ptr, cub->win, cub->move, pos.y, BLOOD);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win, cub->img, 800, 500);
	}
	else if (o_key == KEY_W)
		printf("%d\n", o_key);
	else if (o_key == KEY_S)
		printf("%d\n", o_key);
	else if (o_key == KEY_D)
		printf("%d\n", o_key);
	else if (o_key != KEY_A || o_key != KEY_S
		|| o_key != KEY_W || o_key != KEY_D)
	{
		ft_printf(ERR_KEY);
		return (0);
	}
	return (0);
}
