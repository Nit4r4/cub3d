/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:59 by yacinebenta       #+#    #+#             */
/*   Updated: 2023/01/13 09:11:48 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_data *data)
{
	if (key == KEY_LEFT || key == KEY_RIGHT)
		update_angle(key, data);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		update_position(key, data);
	else if (key == KEY_ESC)
		exit_cub(data);
	else if (key == KEY_M)
		data->is_minimap = ft_bool(data->is_minimap);
	return (0);
}
