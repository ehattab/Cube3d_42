/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:16:20 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/06 20:01:23 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	cast_ray(t_ray *ray, t_player *pl, t_game *game, float angle)
{
	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);
	ray->ray_x = pl->x;
	ray->ray_y = pl->y;
	ray->prev_map_x = ray->ray_x / BLOCK;
	while (!touch(ray->ray_x, ray->ray_y, game))
	{
		if (DEBUG)
			put_pixel(ray->ray_x, ray->ray_y, 0xFF0000, game);
		ray->ray_x += ray->dir_x;
		ray->ray_y += ray->dir_y;
		ray->map_x = ray->ray_x / BLOCK;
		if (ray->map_x != ray->prev_map_x)
			ray->side = 0;
		else
			ray->side = 1;
		ray->prev_map_x = ray->map_x;
	}
	ray->dist = fixed_dist(pl->x, pl->y, ray->ray_x, ray->ray_y, game);
	if (ray->side == 0)
		ray->wall_x = ray->ray_y / BLOCK;
	else
		ray->wall_x = ray->ray_x / BLOCK;
	ray->wall_x -= floor(ray->wall_x);
}


void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		y;
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;

	tex = get_wall_texture(game, ray);
	tex_x = ray->wall_x * tex->width;
	step = (float)tex->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end && y < HEIGHT)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		put_pixel(x, y, *(int *)(tex->data
			+ tex_y * tex->size_line
			+ tex_x * (tex->bpp / 8)),
			game);
		y++;
	}
}


void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;

	if (DEBUG)
		return ;
	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(x, y, game->ceil_color, game);
		y++;
	}
	y = ray->draw_start;
	draw_wall(game, ray, x);
	y = ray->draw_end;
	while (y < HEIGHT)
	{
		put_pixel(x, y, game->floor_color, game);
		y++;
	}
}

void	compute_wall(t_ray *ray)
{
	ray->line_height = (BLOCK / ray->dist) * (WIDTH / 2);
	ray->draw_start = (HEIGHT - ray->line_height) / 2;
	ray->draw_end = ray->draw_start + ray->line_height;
}
