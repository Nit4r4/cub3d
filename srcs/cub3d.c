/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:33 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/08 15:22:43 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
// int	main(int argc, char **argv)
// {
// 	t_cub	cub;

// 	if (argc >= 2)
// 	{
// 		printf("%d\n", read_map(&cub, argv[2]));
// 	}
// }

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (argc == 2)
	{
		parse_map(map, argv);
		printf("%s\n", map->map);
	}
	critical_errors(ERR_ARG);
//	free_map(map);
	return (0);
//	void	*mlx_ptr;
//	void	*win;

//	mlx_ptr = NULL;
		// mlx_ptr = mlx_init(mlx_ptr);
		// win = mlx_new_window(mlx_ptr, 1920, 1080, "hello world");
		// mlx_loop(mlx_ptr);
}

//RE LIRE LES MAN DE MLX
