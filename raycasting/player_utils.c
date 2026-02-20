/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:00:00 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/16 21:05:48 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	move_forward_backward(t_player *player, t_game *game, int dir)
{
	float	speed;
	float	new_x;
	float	new_y;

	speed = 2;
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

	speed = 1.5;
	new_x = player->x - sin(player->angle) * speed * dir;
	new_y = player->y + cos(player->angle) * speed * dir;
	if (can_move(new_x, player->y, game))
		player->x = new_x;
	if (can_move(player->x, new_y, game))
		player->y = new_y;
}

void	rotate_player(t_player *player)
{
	float	angle_speed;

	angle_speed = 0.015;
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
}

void	move_player(t_player *player, t_game *game)
{
	rotate_player(player);
	if (player->key_up)
		move_forward_backward(player, game, 1);
	if (player->key_down)
		move_forward_backward(player, game, -1);
	if (player->key_left)
		move_left_right(player, game, -1);
	if (player->key_right)
		move_left_right(player, game, 1);
}
