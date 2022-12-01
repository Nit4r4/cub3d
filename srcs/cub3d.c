/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/01 08:21:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)

int	main(void)
{
	void	*mlx_ptr;
	void	*win;

	mlx_ptr = NULL;
	mlx_ptr = mlx_init(mlx_ptr);
	win = mlx_new_window(mlx_ptr, 800, 500, "cub3D");
	mlx_pixel_put(mlx_ptr, win,  398, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 399, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 401, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 402, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 250, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 249, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 248, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win,  400, 247, 0X7E0EF4);
	mlx_pixel_put(mlx_ptr, win, 400, 246, 0X7E0EF4);
	//mlx_pixel_put(mlx_ptr, win, 200, 250, 0X7E0EF4);
	mlx_loop(mlx_ptr);
}
