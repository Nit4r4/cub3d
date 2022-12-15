/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:08:53 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/15 08:49:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game(void)
{
	mlx_init();
}

void	init_pos(t_cub *cub)
{
	cub->map.wid = 800;
	cub->map.hei = 500;
}

