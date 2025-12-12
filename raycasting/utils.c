/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:15:32 by ehattab           #+#    #+#             */
/*   Updated: 2025/12/12 22:30:57 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

char	**get_map(void)
{
	char	**map = malloc(sizeof(char *) * 11);
	map[0] = "11111111111111";
	map[1] = "10000000000001";
	map[2] = "10000000000001";
	map[3] = "10000011100001";
	map[4] = "10000000000001";
	map[5] = "10000000000001";
	map[6] = "10000000000001";
	map[7] = "10000000000001";
	map[8] = "10000100000001";
	map[9] = "11111111111111";
	map[10] = NULL;
	return (map);
}

char	**get_map1(void)
{
	char	**map = malloc(sizeof(char *) * 11);
	map[0] = "11111111111111";
	map[1] = "10000000000001";
	map[2] = "1000000S000001";
	map[3] = "10000011100001";
	map[4] = "10000000000001";
	map[5] = "10000000000001";
	map[6] = "10000000000001";
	map[7] = "10000000000001";
	map[8] = "10000100000001";
	map[9] = "11111111111111";
	map[10] = NULL;
	return (map);
}

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
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}