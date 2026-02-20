/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:16:20 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/16 21:01:17 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	set_ray(t_ray *ray, t_player *pl, int x)
{
	double	cam;
	double	dx;
	double	dy;
	double	px;
	double	py;

	dx = cos(pl->angle);
	dy = sin(pl->angle);
	px = -dy * 0.66;
	py = dx * 0.66;
	cam = 2.0 * x / (double)WIDTH - 1.0;
	ray->dir_x = dx + px * cam;
	ray->dir_y = dy + py * cam;
	ray->mx = (int)(pl->x / BLOCK);
	ray->my = (int)(pl->y / BLOCK);
}

void	set_step_y(t_ray *ray, double px, double py)
{
	(void)px;
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sy = (py - ray->my) * ray->dy;
	}
	else
	{
		ray->step_y = 1;
		ray->sy = (ray->my + 1.0 - py) * ray->dy;
	}
}

void	set_step_x(t_ray *ray, double px, double py)
{
	if (ray->dir_x == 0)
		ray->dx = 1e30;
	else
		ray->dx = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->dy = 1e30;
	else
		ray->dy = fabs(1.0 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sx = (px - ray->mx) * ray->dx;
	}
	else
	{
		ray->step_x = 1;
		ray->sx = (ray->mx + 1.0 - px) * ray->dx;
	}
	set_step_y(ray, px, py);
}

void	cast_ray(t_ray *ray, t_game *game)
{
	while (1)
	{
		if (ray->sx < ray->sy)
		{
			ray->sx += ray->dx;
			ray->mx += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sy += ray->dy;
			ray->my += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(ray, game))
			break ;
	}
}

void	set_wall(t_ray *ray, double px, double py)
{
	if (ray->side == 0)
		ray->dist = ray->sx - ray->dx;
	else
		ray->dist = ray->sy - ray->dy;
	if (ray->dist < 0.0001)
		ray->dist = 0.0001;
	ray->height = (int)(HEIGHT / ray->dist);
	ray->start = -ray->height / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = py + ray->dist * ray->dir_y;
	else
		ray->wall_x = px + ray->dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
