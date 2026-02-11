/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:06:12 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	init_player(t_player *player, t_map *map)
{
	player->x = (map->start_x * BLOCK) + (BLOCK / 2);
	player->y = (map->start_y * BLOCK) + (BLOCK / 2);
	player->angle = spawn_angle(
			map->rectangular_map[map->start_y][map->start_x]);
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == D)
		game->player.key_right = false;
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == LEFT)
		game->player.left_rotate = false;
	if (keycode == RIGHT)
		game->player.right_rotate = false;
	return (0);
}

bool	check_corner(float x, float y, t_game *game)
{
	int	mx;
	int	my;

	mx = x / BLOCK;
	my = y / BLOCK;
	if (my < 0 || my >= count_tab_lines(game->map))
		return (false);
	if (mx < 0 || mx >= (int)ft_strlen(game->map[my]))
		return (false);
	if (game->map[my][mx] == '1')
		return (false);
	return (true);
}

bool	can_move(float x, float y, t_game *game)
{
	if (!check_corner(x - P_RADIUS, y - P_RADIUS, game))
		return (false);
	if (!check_corner(x + P_RADIUS, y - P_RADIUS, game))
		return (false);
	if (!check_corner(x - P_RADIUS, y + P_RADIUS, game))
		return (false);
	if (!check_corner(x + P_RADIUS, y + P_RADIUS, game))
		return (false);
	return (true);
}
