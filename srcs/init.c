/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2023/01/10 11:33:29 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/cub3d.h"
/*
void	calloc_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		critical_errors(ERROR);
}
*/

// void	init_degree(t_cub *cub) // fait par Claire
// {
// 	(read map)
// 	if
// }

void	init_game(t_cub *cub)
{
	// cub->map.x = 0;
	// cub->map.y = 0;
	// cub->pos.x = 0;
	// cub->pos.y = 0;
	cub->map.mmap_size = 1;
	mlx_init();
	init_player_pos(cub);
	init_player(cub);
	cub->play.dirx = 0;
	cub->play.diry = degree_to_radian(1);
	cub->play.vue = WIN_HEI / 2;
	cub->pos.a = 0;
}

void	init_player_pos(t_cub *cub)
{
	int	x = 0;
	int	y = 0;

	cub->pos.x = x + 0.5;
	cub->pos.y = y + 0.5;
	if (cub->play.cardi == 'N')
		cub->play.dir = 'N';
	else if (cub->play.cardi == 'S')
		cub->play.dir = 'S';
	else if (cub->play.cardi == 'W')
		cub->play.dir = 'W';
	else if (cub->play.cardi == 'E')
		cub->play.dir = 'E';
	cub->play.cardi = '0';
	/*definir position du player*/
	// cub->pos.x = "N";
	printf("len line : %d\n", cub->map.len_line);
	printf("nb lines : %d\n", cub->map.nb_lines);
	printf("mmap size : %d\n", cub->map.mmap_size);
	// cub->pos.x = cub->map.nb_lines * cub->map.mmap_size + cub->map.mmap_size / 2;
	// cub->pos.y = cub->map.len_line * cub->map.mmap_size + cub->map.mmap_size / 2;
	printf("position x : %d\n", cub->pos.x);
	printf("posiion y : %d\n", cub->pos.y);
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

void	init_player(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->map.x;
	y = cub->map.y;

		cub->pos.x = cub->map.x;
		cub->pos.y = cub->map.y;
}

// void	init_player(t_cub *cub)
// {
// 	int		x;
// 	int		y;
// 	int		pos_x[x];
// 	int		pos_y[y];

// 	y = -1;
// 	while (++y < cub->map.nb_lines)
// 	{
// 		x = -1;
// 		while (++x < cub->map.len_line)
// 		{
// 			if (ft_strchr("NSWE", cub->map.tabmap[y][x]))
// 			{
// 				//cub->map.tabmap[cub->map.y][cub->map.x] = cub->map.tabmap[y][x];
// 				cub->pos.x = cub->map.x;
// 				cub->pos.y = cub->map.y;
// 			}
// 		}
// 	}
// }
