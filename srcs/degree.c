/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:08:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/11 15:45:35 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180.0);
}

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}