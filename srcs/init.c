/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2022/12/22 13:10:44 by vferraro         ###   ########.fr       */
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

// void	init_player_pos(t_cub *cub)
// {
// 	int	x = 0;
// 	int	y = 0;
// 	char*cardi = NULL;
	
// 	cub->pos.x = x + 0.5;
// 	cub->pos.y = y + 0.5;
// 	if (*cardi == 'N')
// 		cub->play.dir = 'N';
// 	if (*cardi == 'S')
// 		cub->play.dir = 'S';
// 	if (*cardi == 'W')
// 		cub->play.dir = 'W';
// 	if (*cardi == 'E')
// 		cub->play.dir = 'E';
// 	*cardi = '0';
// }

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
