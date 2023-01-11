/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:13:40 by creyt             #+#    #+#             */
/*   Updated: 2023/01/11 14:43:21 by creyt            ###   ########.fr       */
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
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free_tab(map->tabmap, map->nb_lines);
}

void	free_cub(t_cub *cub)
{
	int	i;

	i = 0;
	//free_map(cub->map);
	//free(cub->map);
	//free(cub->play);
	free(cub->ray);
	while (i < cub->nbr_t)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->tex[i].tex);
		i++;
	}
	free(cub->tex);
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	mlx_destroy_window(cub->mlx_ptr, cub->win);
	free(cub);
}
