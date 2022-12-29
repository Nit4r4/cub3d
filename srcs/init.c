/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2022/12/29 16:40:40 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calloc_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		critical_errors(ERROR);
	cub->play = ft_calloc(sizeof(t_player), 1);
	if (!cub->play)
		critical_errors(ERROR);
	cub->pos = ft_calloc(sizeof(t_vect), 1);
	if (!cub->pos)
		critical_errors(ERROR);
}

t_cub	*init_game(char **argv)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		critical_errors(ERR_MALLOC);
	calloc_cub(cub);
	cub->mlx_ptr = mlx_init();
	cub->play->dirx = 0;
	cub->play->diry = degree_to_radian(1);
	cub->play->vue = WIN_HEI / 2;
	cub->pos->a = 0;
	parse_map(cub->map, argv);
	player_pos(cub);
	return (cub);
}

int	init_player(char c, int x, int y, t_cub *cub)
{
	int	med;

	med = cub->map->size_tile / 2;
	if (c == 'N')
		cub->play->angle = 90. * (M_PI / 180.0);
	else if (c == 'W')
		cub->play->angle = 180. * (M_PI / 180.0);
	else if (c == 'E')
		cub->play->angle = 0. * (M_PI / 180.0);
	else if (c == 'S')
		cub->play->angle = 270. * (M_PI / 180.0);
	else
		return (0);
	cub->play->x = (float)(x * cub->map->size_tile + med);
	cub->play->y = (float)(y * cub->map->size_tile + med);
	return (1);
}

void	player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	if (cub->play->initiated == 1)
		return ;
	while (i < cub->map->nb_lines)
	{
		j = 0;
		while (j < cub->map->len_line)
		{
			if (init_player(cub->map->tabmap[i][j], j, i, cub))
			{
				cub->play->initiated = 1;
				return ;
			}
			j++;
		}
		i++;
	}
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
