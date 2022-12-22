/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2022/12/22 13:20:45 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calloc_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		critical_errors(ERROR);
}

void	init_game(t_cub *cub)
{
	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		critical_errors(ERROR_MALLOC);
	calloc_cub(cub);
	mlx_init();
}

// void	set_pos(t_cub *cub, double x, double y)
// {
// 	cub->pos->x = x;
// 	cub->pos->y = y;
// }

// void	init_pos(t_cub *cub)
// {
// 	cub->move = 0;
// 	cub->map.wid = WIN_WID;
// 	cub->map.hei = WIN_HEI;
// 	set_pos(cub->move, 0, 0);
// 	set_pos(cub->move_x, 0, 0);
// }
