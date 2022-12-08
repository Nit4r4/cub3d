/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:13:40 by creyt             #+#    #+#             */
/*   Updated: 2022/12/08 10:22:16 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	free(map->map);
	free_tab(map->tabmap, map->nb_lines);
}

void	free_cub(t_cub *cub)
{
	int	i;

	i = 0;
	free_map(&cub->map);
	free(&cub->map);
	free(cub);
}
