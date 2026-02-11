/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2026/02/11 21:47:34 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	build_hex(char *line, t_color *color)
{
	char	**split;
	int		hex;

	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		printf("Error\nRGB line could not be parsed\n");
		if (split)
			free_map(split);
		return (-1);
	}
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	free_map(split);
	hex = (color->r << 16) | (color->g << 8) | color->b;
	return (hex);
}

int	parse_rgb(char *line, t_color *color)
{
	if (!line)
	{
		printf("Error\nRGB value is empty\n");
		return (-1);
	}
	if (check_rgb(line))
	{
		printf("Error\nRGB must follow R,G,B format\n");
		return (-1);
	}
	if (check_nums(line))
	{
		printf("Error\nRGB values must be integers between 0 and 255\n");
		return (-1);
	}
	return (build_hex(line, color));
}

int	parse_map_data(char **av, t_map *map)
{
	validate_config(map);
	if (parse_config(map))
		return (free_map_data(map), 1);
	check_path(map);
	replace_spaces(map->after_map);
	validate_map(map);
	map->mapp_scan = copy_map_data(map->after_map, av[1]);
	map->rectangular_map = make_rectangle(map->mapp_scan, map);
	check_holes(map);
	find_player(map->rectangular_map, map);
	map->height = count_tab_lines(map->rectangular_map);
	return (0);
}

int	parsing(int ac, char **av, t_map *map)
{
	if (ac < 2)
	{
		printf("Error\nMap file path is required\n");
		return (1);
	}
	if (ac > 2)
	{
		printf("Error\nToo many arguments (expected one map file)\n");
		return (1);
	}
	if (check_file(av[1]))
		return (1);
	ft_bzero(map, sizeof(t_map));
	map->copy_map = load_file(av[1], map);
	if (!map->copy_map)
		return (1);
	map->after_map = split_config_map(map->copy_map, map);
	if (!map->after_map)
		return (free_map_data(map), 1);
	return (parse_map_data(av, map));
}

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;

	if (parsing(ac, av, &map))
		return (1);
	init_game(&game, &map);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
