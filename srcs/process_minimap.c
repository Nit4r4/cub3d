/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:44:39 by creyt             #+#    #+#             */
/*   Updated: 2023/01/10 15:49:14 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_grid(t_grid *grid, t_cub *cub)
{
	grid->size = cub->map->draw_tile;
	grid->p_x = floor(cub->p->x / cub->map->size_tile);
	grid->p_y = floor(cub->p->y / cub->map->size_tile);
	grid->i = grid->p_y - 5;
	grid->k = 0;
}
