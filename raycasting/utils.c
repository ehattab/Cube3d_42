/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:15:32 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/16 21:01:17 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

float	spawn_angle(char p)
{
	if (p == 'N')
		return (3 * PI / 2);
	else if (p == 'S')
		return (PI / 2);
	else if (p == 'E')
		return (0);
	else if (p == 'W')
		return (PI);
	return (0);
}

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

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].img)
			mlx_destroy_image(game->mlx, game->texture[i].img);
		i++;
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map_data)
		free_map_data(game->map_data);
	exit(0);
	return (0);
}

int	is_wall(t_ray *ray, t_game *game)
{
	if (ray->my < 0 || ray->my >= game->map_data->height)
		return (1);
	if (ray->mx < 0
		|| ray->mx >= (int)ft_strlen(game->map[ray->my]))
		return (1);
	if (game->map[ray->my][ray->mx] == '1')
		return (1);
	return (0);
}

void	draw_debug(t_game *game, t_player *player)
{
	int	pos[2];

	pos[0] = player->x;
	pos[1] = player->y;
	draw_square(pos, 10, 0x00FF00, game);
	draw_map(game);
}
