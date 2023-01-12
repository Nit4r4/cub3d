/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:51:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/12 10:51:38 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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