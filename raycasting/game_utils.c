/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:00:00 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 16:54:17 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (y < 0 || y >= game->map_data->height)
		return (true);
	if (x < 0 || x >= (int)ft_strlen(game->map[y]))
		return (true);
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float *p1, float *p2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = p2[0] - p1[0];
	delta_y = p2[1] - p1[1];
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	render_rays(t_game *game, t_player *player)
{
	t_ray	ray;
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		cast_ray(&ray, player, game, start_x);
		compute_wall(&ray);
		draw_column(game, &ray, i);
		start_x += fraction;
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
