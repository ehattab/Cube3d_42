/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:11:36 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/06 19:37:41 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, color, game);
		put_pixel(x, y + i, color, game);
		put_pixel(x + size, y + i, color, game);
		put_pixel(x + i, y + size, color, game);
		i++;
	}
}

void	draw_map(t_game *game)
{
	char	**map = game->map;
	int		color = 0x0000FF;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
			x++;
		}
		y++;
	}
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

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	t_ray		ray;
	float		fraction;
	float		start_x;
	int			i;

	player = &game->player;
	move_player(player, game);
	clear_image(game);
	if (DEBUG)
		draw_debug(game, player);
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
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
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
	game->map = replace_player_with_zero(map->rectangular_map);
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
