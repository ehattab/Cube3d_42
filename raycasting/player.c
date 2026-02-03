/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:06:12 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/02 18:51:31 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	init_player(t_player *player, t_map *map)
{
	player->x = (map->start_x * BLOCK) + (BLOCK / 2);
	player->y = (map->start_y * BLOCK) + (BLOCK / 2);
	player->angle = spawn_angle(map->rectangular_map[map->start_y][map->start_x]);
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
	if(keycode == W)
		game->player.key_up = true;
	if(keycode == S)
		game->player.key_down = true;
	if(keycode == D)
		game->player.key_right = true;
	if(keycode == A)
		game->player.key_left = true;
	if(keycode == LEFT)
		game->player.left_rotate = true;
	if(keycode == RIGHT)
		game->player.right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if(keycode == W)
		game->player.key_up = false;
	if(keycode == S)
		game->player.key_down = false;
	if(keycode == D)
		game->player.key_right = false;
	if(keycode == A)
		game->player.key_left = false;
	if(keycode == LEFT)
		game->player.left_rotate = false;
	if(keycode == RIGHT)
		game->player.right_rotate = false;
	return (0);
}

bool	can_move(float x, float y, t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (x - P_RADIUS) / BLOCK;
	map_y = (y - P_RADIUS) / BLOCK;
	if (map_y < 0 || map_y >= count_lines_tab(game->map))
		return false;
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map[map_y]))
		return false;
	if (game->map[map_y][map_x] == '1')
		return false;
	map_x = (x + P_RADIUS) / BLOCK;
	map_y = (y - P_RADIUS) / BLOCK;
	if (game->map[map_y][map_x] == '1')
		return false;
	map_x = (x - P_RADIUS) / BLOCK;
	map_y = (y + P_RADIUS) / BLOCK;
	if (game->map[map_y][map_x] == '1')
		return false;
	map_x = (x + P_RADIUS) / BLOCK;
	map_y = (y + P_RADIUS) / BLOCK;
	if (game->map[map_y][map_x] == '1')
		return false;
	return true;
}

void	move_forward_backward(t_player *player, t_game *game, int dir)
{
	float	speed;
	float	new_x;
	float	new_y;

	speed = 10;
	new_x = player->x + cos(player->angle) * speed * dir;
	new_y = player->y + sin(player->angle) * speed * dir;
	if (can_move(new_x, player->y, game))
		player->x = new_x;
	if (can_move(player->x, new_y, game))
		player->y = new_y;
}

void	move_left_right(t_player *player, t_game *game, int dir)
{
	float	speed;
	float	new_x;
	float	new_y;

	speed = 6;
	new_x = player->x - sin(player->angle) * speed * dir;
	new_y = player->y + cos(player->angle) * speed * dir;
	if (can_move(new_x, player->y, game))
		player->x = new_x;
	if (can_move(player->x, new_y, game))
		player->y = new_y;
}

void	move_player(t_player *player, t_game *game)
{
	float	angle_speed;

	angle_speed = 0.08;
	if (player->left_rotate)
	{
		player->angle -= angle_speed;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	if (player->right_rotate)
	{
		player->angle += angle_speed;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	if (player->key_up)
		move_forward_backward(player, game, 1);
	if (player->key_down)
		move_forward_backward(player, game, -1);
	if (player->key_left)
		move_left_right(player, game, -1);
	if (player->key_right)
		move_left_right(player, game, 1);
}
