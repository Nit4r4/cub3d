/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/13 09:07:52 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		err_msg(ERR_USAGE);
	if (SCREENWIDTH <= 0 || SCREENHEIGHT <= 0)
		err_msg(ERR_SCREEN);
	data = init_data(av);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx,
			SCREENWIDTH, SCREENHEIGHT, "Hello cub3D");
	mlx_loop_hook(data->mlx->mlx, ft_loop_hook, data);
	mlx_hook(data->mlx->mlx_win, 2, 1, key_hook, data);
	mlx_hook(data->mlx->mlx_win, 17, 0, exit_cub, data);
	mlx_loop(data->mlx->mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
