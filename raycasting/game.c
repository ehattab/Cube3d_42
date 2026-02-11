/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:11:36 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int *pos, int size, int color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(pos[0] + i, pos[1], color, game);
		put_pixel(pos[0], pos[1] + i, color, game);
		put_pixel(pos[0] + size, pos[1] + i, color, game);
		put_pixel(pos[0] + i, pos[1] + size, color, game);
		i++;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	int		pos[2];

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				pos[0] = x * BLOCK;
				pos[1] = y * BLOCK;
				draw_square(pos, BLOCK, 0x0000FF, game);
			}
			x++;
		}
		y++;
	}
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game, t_map *map)
{
	game->map_data = map;
	init_player(&game->player, map);
	game->map = remove_player(map->rectangular_map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3d");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	game->ceil_color = map->ceiling_hex;
	game->floor_color = map->floor_hex;
	load_textures(game, map);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
