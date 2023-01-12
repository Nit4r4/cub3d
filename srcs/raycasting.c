/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:43:02 by creyt             #+#    #+#             */
/*   Updated: 2023/01/12 11:34:32 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_wall(int x, int y, t_cub *cub, t_ray *ray)
{
	if (x <= 0 || y <= 0)
		return (1);
	if (x / cub->map->size_tile > cub->map->len_line - 1
		|| y / cub->map->size_tile > cub->map->nb_lines - 1)
		return (1);
	if (cub->map->tabmap[y / cub->map->size_tile]
		[x / cub->map->size_tile] == '1')
	{
		ray->side = 0;
		return (1);
	}
	return (0);
}

void	dup_ray(t_ray *ray, t_ray *dup)
{
	dup->x = ray->x;
	dup->y = ray->y;
	dup->delta = ray->delta;
	dup->side = ray->side;
	dup->ver_hor = ray->ver_hor;
	dup->relative_angle = ray->relative_angle;
	dup->angle = ray->angle;
}

t_ray	*select_ray(t_cub *cub, float angle, t_ray *ray)
{
	int		d_hor;
	int		d_ver;
	t_ray	last_ray;
	t_ray	dup;

	ray->relative_angle = angle - cub->pos->a;
	dup_ray(ray, &last_ray);
	get_horizontal_ray(cub, ray, angle);
	d_hor = ray->delta;
	dup_ray(ray, &dup);
	get_vertical_ray(cub, ray, angle);
	d_ver = ray->delta;
	if (d_hor < d_ver)
		dup_ray(&dup, ray);
	if (ft_abs(d_ver - d_hor) <= 0)
	{
		if (get_wall(last_ray.x, last_ray.y + 1, cub, &last_ray)
			&& get_wall(last_ray.x, last_ray.y - 1, cub, &last_ray))
			dup_ray(&dup, ray);
		else if (get_wall(last_ray.x + 1, last_ray.y, cub, ray)
			&& get_wall(last_ray.x - 1, last_ray.y, cub, ray))
			get_vertical_ray(cub, &last_ray, angle);
	}
	return (ray);
}

void	get_vertical_ray(t_cub *cub, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle > 0 && angle < degree_to_radian(180))
		ray->y = floor(cub->pos->y / cub->map->size_tile)
			* cub->map->size_tile - 0.001;
	else
	{
		ray->y = floor(cub->pos->y / cub->map->size_tile)
			* cub->map->size_tile + cub->map->size_tile;
		direction = -1;
	}
	ray->x = (cub->pos->y - ray->y) / tan(angle) + cub->pos->x;
	while (!get_wall(ray->x, ray->y, cub, ray))
	{
		ray->y -= cub->map->size_tile * direction;
		ray->x += cub->map->size_tile / tan(angle) * direction;
	}
	ray->delta = sqrt(pow(cub->pos->x - ray->x, 2.)
			+ pow(cub->pos->y - ray->y, 2.));
	ray->ver_hor = 0;
}

void	get_horizontal_ray(t_cub *cub, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle <= degree_to_radian(90) || angle >= degree_to_radian(270))
		ray->x = floor(cub->pos->x / cub->map->size_tile)
			* cub->map->size_tile + cub->map->size_tile;
	else
	{
		ray->x = floor(cub->pos->x / cub->map->size_tile)
			* cub->map->size_tile - 0.001;
		direction = -1;
	}
	ray->y = cub->pos->y + (cub->pos->x - ray->x) * tan(angle);
	while (!get_wall(ray->x, ray->y, cub, ray))
	{
		ray->x += cub->map->size_tile * direction;
		ray->y -= cub->map->size_tile * tan(angle) * direction;
	}
	ray->delta = sqrt(pow(cub->pos->x - ray->x, 2.)
			+ pow(cub->pos->y - ray->y, 2.));
	ray->ver_hor = 1;
}
