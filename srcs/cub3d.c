/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/23 15:58:42 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)

int main (void)
{
	mlx_ptr_t	*mlx_ptr = NULL;

	while (42)
		mlx_new_window(mlx_ptr, 512, 800, "jeu videal");
	return (0);
}

RE LIRE LES MAN DE MLX 