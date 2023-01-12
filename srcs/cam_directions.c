/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:54:02 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 11:49:54 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_camera_r(t_cub *cub)
{
	cub->pos->a -= SPD;
	if (cub->pos->a <= 0.)
		cub->pos->a = 360.;
}

void	ft_camera_l(t_cub *cub)
{
	cub->pos->a += SPD;
	if (cub->pos->a >= 360.)
		cub->pos->a = 0.;
}
