/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2026/02/01 17:12:33 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int ac, char **av, t_map *map)
{
	if (ac != 2)
		return (1);
	if (check_file(av[1]))
		return (1);
	ft_bzero(map, sizeof(t_map));
	map->copy_map = cpy_map(av[1]);
	if (!map->copy_map)
		return (1);
	map->after_map = after_path(map->copy_map, map);
	if (!map->after_map)
		return (1);
	check_instruction(map->before_map);
	check_path(map->before_map);
	map_valid(map->after_map);
	map->mapp_scan = map_scan(map->after_map, av[1]);
	if (!map->mapp_scan)
		return (1);
	map->rectangular_map = rectangulare_map(map->mapp_scan, map);
	if (!map->rectangular_map)
		return (1);
	check_rectangle_map(map->rectangular_map);
	return (0);
}

void	replace_player_with_zero(char **map, t_map *map_struct)
{
	int	i;
	int	j;
	int	found;

	if (!map || !map_struct)
		ft_error("error: map is NULL\n", map);
	found = 0;
	i = 0;
	while (map[i] && !found)
	{
		j = 0;
		while (map[i][j] && !found)
		{
			if (map[i][j] == 'N'
				|| map[i][j] == 'S'
				|| map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				map_struct->start_x = i;
				map_struct->start_y = j;
				map[i][j] = '0';
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (!found)
		ft_error("error: no starting position found\n", map);
}

int	parse_rgb(char *line, t_color *color)
{
	char	**split;
	int		hex;

	if (!line || !color)
		return (-1);
	check_rgb(line);
	split = ft_split(line, ',');
	if (!split)
		return (-1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		free_map(split);
		ft_error("Error\nRGB values must be between 0 and 255\n", NULL);
	}
	hex = (color->r << 16) | (color->g << 8) | color->b;
	free_map(split);
	return (hex);
}


int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;
	t_gmap	gmap;

	if (parsing(ac, av, &map))
		return (1);
	gmap.map = get_map1();
	if (!gmap.map)
		return (1);
	search_position2(gmap.map, &gmap);
	gmap.p = gmap.map[gmap.y][gmap.x];
	init_game(&game, &gmap);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
