/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/24 14:12:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)

int	main (void)
{
	void	*mlx_ptr;
	void	*win;

	mlx_ptr = NULL;
	mlx_ptr = mlx_init(mlx_ptr);
	win = mlx_new_window(mlx_ptr, 800, 500, "hello world");
	mlx_loop(mlx_ptr);
}
