/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:08:36 by vferraro          #+#    #+#             */
/*   Updated: 2022/12/22 14:10:30 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180.0);
}