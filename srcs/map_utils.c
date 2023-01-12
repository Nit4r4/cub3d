/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:57 by creyt             #+#    #+#             */
/*   Updated: 2023/01/12 10:46:52 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	get_floor_or_ceiling(t_map *map, int i)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 0;
	while (!ft_isdigit(map->map[i]))
		i++;
	r = ft_atoi(map->map + i);
	i += ft_nbrlen(r);
	while (!ft_isdigit(map->map[i]))
		i++;
	g = ft_atoi(map->map + i);
	i += ft_nbrlen(g);
	while (!ft_isdigit(map->map[i]))
		i++;
	b = ft_atoi(map->map + i);
	return (create_trgb(colorfool(a), colorfool(r), colorfool(g),
			colorfool(b)));
}

static int	get_info(t_map *map, char *type, int i)
{
	if (!strncmp(map->map + i, type, ft_strlen(type)))
	{
		i += (int)ft_strlen(type);
		while (ft_isspace(map->map[i]))
			i++;
		if (!ft_strncmp(type, "NO ", 3))
			map->no = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "SO ", 3))
			map->so = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "WE ", 3))
			map->we = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "EA ", 3))
			map->ea = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "F ", 2))
			map->floor = get_floor_or_ceiling(map, i);
		else if (!ft_strncmp(type, "C ", 2))
			map->ceiling = get_floor_or_ceiling(map, i);
	}
	return (i);
}

int	get_elems(t_map *map)
{
	int	i;
	int	count_nl;

	i = -1;
	count_nl = 0;
	while (map->map[++i] && count_nl <= 6)
	{
		if (map->map[i] == '\n')
		{
			count_nl++;
			continue ;
		}
		if (count_nl == 6)
			break ;
		if (ft_isspace(map->map[i]))
			continue ;
		i = get_info(map, "NO ", i);
		i = get_info(map, "SO ", i);
		i = get_info(map, "WE ", i);
		i = get_info(map, "EA ", i);
		i = get_info(map, "F ", i);
		i = get_info(map, "C ", i);
	}
	return (i);
}
