/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:44:55 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/16 21:01:17 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

int	get_tex_x(t_ray *ray, t_img *tex)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;

	tex = get_wall_texture(game, ray);
	tex_x = get_tex_x(ray, tex);
	step = 1.0 * tex->height / ray->height;
	tex_pos = (ray->start - HEIGHT / 2
			+ ray->height / 2.0) * step;
	y = ray->start;
	while (y <= ray->end)
	{
		put_pixel(x, y, *(int *)(tex->data
				+ ((int)tex_pos & (tex->height - 1)) * tex->size_line
				+ tex_x * (tex->bpp / 8)), game);
		tex_pos += step;
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;

	if (DEBUG)
		return ;
	y = 0;
	while (y < ray->start)
	{
		put_pixel(x, y, game->ceil_color, game);
		y++;
	}
	draw_wall(game, ray, x);
	y = ray->end + 1;
	while (y < HEIGHT)
	{
		put_pixel(x, y, game->floor_color, game);
		y++;
	}
}

void	render_rays(t_game *game, t_player *player)
{
	t_ray	ray;
	double	px;
	double	py;
	int		i;

	px = player->x / (double)BLOCK;
	py = player->y / (double)BLOCK;
	i = 0;
	while (i < WIDTH)
	{
		set_ray(&ray, player, i);
		set_step_x(&ray, px, py);
		cast_ray(&ray, game);
		set_wall(&ray, px, py);
		draw_column(game, &ray, i);
		i++;
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	move_player(player, game);
	clear_image(game);
	if (DEBUG)
		draw_debug(game, player);
	render_rays(game, player);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
