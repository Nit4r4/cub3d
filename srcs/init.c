/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2022/12/15 13:40:14 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
void	calloc_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		critical_errors(ERROR);
}
*/
void	init_game(void)
{
	mlx_init();
}

void	init_pos(t_cub *cub)
{
	cub->map.wid = 800;
	cub->map.hei = 500;
}
