/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:02:46 by creyt             #+#    #+#             */
/*   Updated: 2022/12/15 10:35:54 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*lis les 6 infos au-dessus de la map dans le .cub !! les infos sont enregistr
dans les variables de la map. substr, permet de rentrer les infos sans les
prefixes (no, ea, etc) et le \n*/

void	check_info_map(t_map *map, char *info, int line)
{
	if (line == 0 && ft_strncmp(info, "NO ", 3) == 0)
	{
		map->no = ft_substr(info, 3, ft_strlen(info) - 4);
		printf("%s\n", map->no);
		return ;
	}
	else if (line == 1 && ft_strncmp(info, "SO ", 3) == 0)
	{
		map->so = ft_substr(info, 3, ft_strlen(info) - 4);
		printf("%s\n", map->so);
		return ;
	}
	else if (line == 2 && ft_strncmp(info, "WE ", 3) == 0)
	{
		map->we = ft_substr(info, 3, ft_strlen(info) - 4);
		printf("%s\n", map->we);
		return ;
	}
	else if (line == 3 && ft_strncmp(info, "EA ", 3) == 0)
	{
		map->ea = ft_substr(info, 3, ft_strlen(info) - 4);
		printf("%s\n", map->ea);
		return ;
	}
	else if (line == 4 && ft_strncmp(info, "F ", 2) == 0)
	{
		map->fl = ft_substr(info, 2, ft_strlen(info) - 3);
		printf("%s\n", map->fl);
		return ;
	}
	else if (line == 5 && ft_strncmp(info, "C ", 2) == 0)
	{
		map->cei = ft_substr(info, 2, ft_strlen(info) - 3);
		printf("%s\n", map->fl);
		return ;
	}
	critical_errors(ERR_MAP_INFO);
}

/* on check les caracteres speciaux/interdits en premier lieu, on lit le haut
d'ou le fait qu'on fait un strtrim pour enlever les char speciaux
on enregistre le tout dans une chaine de characteres (*map) */

void	get_map(t_map *map, int fd)
{
	char	*gnl;
	char	*tmp;

	tmp = get_next_line(fd);
	gnl = ft_strtrim(tmp, IS_SPACE);
	free(tmp);
	while (gnl)
	{
		if (map->nb_lines > 6 && map->len_line < (int)ft_strlen(gnl))
			map->len_line = (int)ft_strlen(gnl);
		if (ft_strlen(gnl) > 1)
		{
			if (map->nb_lines < 6)
			{
				check_info_map(map, gnl, map->nb_lines);
			}
			else if (!map->map)
				map->map = ft_strdup(gnl);
			else
				map->map = ft_strjoin_cub(map->map, gnl, 1);
			map->nb_lines++;
		}
		free(gnl);
		tmp = get_next_line(fd);
		gnl = ft_strtrim(tmp, IS_SPACE);
		free(tmp);
	}
	free(gnl);
	printf("%s\n", map->map);
}

void	get_tabmap(t_map *map, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nb_lines)
	{
		x = -1;
		while (++x < map->len_line && map->map[i])
		{
			if (map->map[i] != '\n')
			{
				if (ft_strchr("01NSWE", map->map[i]) || map->map[i] == ' ')
				{
					if (map->map[i] != ' ')
						map->tabmap[y][x] = (char)ft_toupper(map->map[i]);
				}
				else
					map->tabmap[y][x] = 'X';
			}
			else
				continue ;
			i++;
		}
		i++;
	}
}

void	init_tabmap(t_map *map)
{
	int	i;
	int	j;

	map->tabmap = ft_calloc(sizeof(char *), map->nb_lines);
	if (!map->tabmap)
		critical_errors(ERROR);
	i = -1;
	while (++i < map->nb_lines)
	{
		map->tabmap[i] = ft_calloc(sizeof(char), map->len_line);
		if (!map->tabmap[i])
			critical_errors(ERROR);
	}
	i = -1;
	while (++i < map->nb_lines)
	{
		j = -1;
		while (++j < map->len_line)
			map->tabmap[i][j] = '.';
	}
}

void	parse_map(t_map *map, char **av)
{
	int	fd;
	int	i;

	check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		critical_errors(ERR_FD);
	map->map = NULL;
	map->nb_lines = 0;
	map->len_line = 0;
	get_map(map, fd);
	map->nb_lines -= 6;
	map->len_line -= 1;
	i = get_elems(map);
	init_tabmap(map);
	get_tabmap(map, i);
	check_tabmap(map);
}
