/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:46:48 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/29 13:20:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/************************************************
* Gere le message d'erreur et exit le programme *
************************************************/
void	critical_errors(char *str)
{
	ft_printf("\n--------------------------\n\n%s\
%s\n--------------------------\n\n", ERROR, str);
	exit(EXIT_FAILURE);
}

/******************************************************************
**	verifier que mon fichier a lire est un .*cub et rien d'autre **
*******************************************************************/
void	check_file(char *str)
{
	char	*compare;
	int		len;

	len = ft_strlen(str);
	if (!str)
		return ;
	compare = ft_strnstr(str, ".cub", len);
	if (compare && ft_strlen(compare) == 4)
	{
		return ;
	}
	critical_errors(ERR_FILE);
}

void	check_border_map(t_map *map, int x, int y)
{
	if (y == 0 || y == map->nb_lines - 1 || x == 0 || x == map->len_line -1)
		if (map->tabmap[y][x] != '.' && map->tabmap[y][x] != '1')
			critical_errors(MAP_ERR_HO);
}

void	check_center_map(t_map *map, int x, int y)
{
	if (x > 0 && y > 0 && x < map->len_line - 1 && y < map->nb_lines - 1)
	{
		if ((map->tabmap[y][x] == '0' && map->tabmap[y][x - 1] == '.')
			|| (map->tabmap[y][x] == '0' && map->tabmap[y][x + 1] == '.')
			|| (map->tabmap[y][x] == '0' && map->tabmap[y - 1][x] == '.')
			|| (map->tabmap[y][x] == '0' && map->tabmap[y + 1][x] == '.'))
		{
			critical_errors(MAP_ERR_HO_2);
		}
	}
}

void	check_tabmap(t_map *map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = -1;
	while (++y < map->nb_lines)
	{
		x = -1;
		while (++x < map->len_line)
		{
			if (map->tabmap[y][x] == 'X')
				critical_errors(ERR_MAP_CONTENT);
			check_border_map(map, x, y);
			check_center_map(map, x, y);
			if (ft_strchr("NSWE", map->tabmap[y][x]))
				player++;
		}
	}
	if (map->len_line < 3 || map->nb_lines < 3)
		critical_errors(ERR_MAP_SIZE);
	if (player != 1)
		critical_errors(ERR_MAP_PLAYER);
}
