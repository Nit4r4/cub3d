/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:51:15 by creyt             #+#    #+#             */
/*   Updated: 2023/01/11 14:51:56 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/cub3d.h"
/*
void	malloc_my_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		err_msg(ERR_MALLOC);
	cub->play = ft_calloc(sizeof(t_player), 1);
	if (!cub->p)
		err_msg(ERR_MALLOC);
	cub->t = ft_calloc(sizeof(t_texture), cub->nbr_t);
	if (!cub->t)
		err_msg(ERR_MALLOC);
	cub->ray = ft_calloc(SCREENWIDTH, sizeof(t_ray));
	if (!cub->ray)
		err_msg(ERR_MALLOC);
}
*/
// void	init_degree(t_cub *cub) // fait par Claire
// {
// 	(read map)
// 	if 
// }

void	init_game(t_cub *cub)
{
	// cub->map.x = 0;
	// cub->map.y = 0;
	// cub->pos.x = 0;
	// cub->pos.y = 0;
	cub->minimap = 1;
	cub->map.mmap_size = 1;
	cub->mlx_ptr = mlx_init();
	init_player_pos(cub);
	init_player(cub);
	cub->play.dirx = 0;
	cub->play.diry = degree_to_radian(1);
	cub->play.vue = WIN_HEI / 2;
	cub->pos.a = 0;
}

void	init_player_pos(t_cub *cub)
{
	int	x = 0;
	int	y = 0;

	cub->pos.x = x + 0.5;
	cub->pos.y = y + 0.5;
	if (cub->play.cardi == 'N')
		cub->play.dir = 'N';
	else if (cub->play.cardi == 'S')
		cub->play.dir = 'S';
	else if (cub->play.cardi == 'W')
		cub->play.dir = 'W';
	else if (cub->play.cardi == 'E')
		cub->play.dir = 'E';
	cub->play.cardi = '0';
	/*definir position du player*/
	// cub->pos.x = "N";
	cub->play.vue = WIN_HEI / 2;
	printf("len line : %d\n", cub->map.len_line);
	printf("nb lines : %d\n", cub->map.nb_lines);
	printf("mmap size : %d\n", cub->map.mmap_size);
	// cub->pos.x = cub->map.nb_lines * cub->map.mmap_size + cub->map.mmap_size / 2;
	// cub->pos.y = cub->map.len_line * cub->map.mmap_size + cub->map.mmap_size / 2;
	printf("position x : %d\n", cub->pos.x);
	printf("posiion y : %d\n", cub->pos.y);
}

void	init_player(t_cub *cub)
{
//	int	x;
//	int	y;

	cub->play.vue = WIN_HEI / 2;
//	x = cub->map.x;
//	y = cub->map.y;

		cub->pos.x = cub->map.x;
		cub->pos.y = cub->map.y;
}

int	init_texture(t_cub *cub)
{
	int	i;

	i = -1;
	cub->tex[0].tex = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->map.no, &cub->tex[0].wid_tex, &cub->tex[0].hei_tex);
	cub->tex[1].tex = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->map.so, &cub->tex[1].wid_tex, &cub->tex[1].hei_tex);
	cub->tex[2].tex = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->map.ea, &cub->tex[2].wid_tex, &cub->tex[2].hei_tex);
	cub->tex[3].tex = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->map.we, &cub->tex[3].wid_tex, &cub->tex[3].hei_tex);
	// cub->tex[4].tex = mlx_xpm_file_to_image(cub->mlx_ptr, tex_DOOR,
	// 		&cub->tex[4].wid_tex, &cub->tex[4].hei_tex);
	// cub->tex[5].tex = mlx_xpm_file_to_image(cub->mlx_ptr, tex_KNIFE,
	// 		&cub->tex[5].wid_tex, &cub->tex[5].hei_tex);
	while (++i < cub->nbr_t)
	{
		if (!cub->tex[i].tex)
			critical_errors(ERR_TEX);
		cub->tex[i].addr = (int *)mlx_get_data_addr(cub->tex[i].tex,
				&cub->tex[0].bits_nb, &cub->tex[i].len_line, &cub->tex[i].endien);
	}
	return (1);
}