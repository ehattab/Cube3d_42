/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:15:32 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/06 18:41:34 by ehattab          ###   ########.fr       */
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
		free_full_map_data(game->map_data);
	exit(0);
	return (0);
}

void	draw_debug(t_game *game, t_player *player)
{
	draw_square(player->x, player->y, 10, 0x00FF00, game);
	draw_map(game);
}
