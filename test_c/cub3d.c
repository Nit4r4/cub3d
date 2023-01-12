/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/16 10:58:14 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
typedef struct s_cub
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*addr;
	char	*mlx_add;
	int		mlx_bpp;
	int		mlx_nd; //endian
	int		mlx_len;
	int		move;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_cub;

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
				*(unsigned int*)dst = color;
}

int	main(void)
{
	t_cub	cub;
	cub.win = mlx_new_window(cub.mlx_ptr, 800, 500, "cub3d");
	cub.img = mlx_new_image(cub.mlx_ptr, 800, 500);
	cub.addr = mlx_get_data_addr(cub.img, &cub.bits_per_pixel,
			&cub.line_length, &cub.endian);
	my_mlx_pixel_put(cub.img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(cub.mlx_ptr, cub.win, cub.img, 0, 0);
	mlx_loop(cub.mlx_ptr);
	return (0);
}

//RE LIRE LES MAN DE MLX
