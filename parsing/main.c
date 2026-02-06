/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2026/02/06 19:35:42 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_rgb(char *line, t_color *color)
{
	char	**split;
	int		hex;

	if (!line)
		return (-1);
	check_rgb(line);
	if (check_nums(line)) 
		return (-1);
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
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

int parsing(int ac, char **av, t_map *map)
{
	if (ac != 2 || check_file(av[1]))
		return (1);
	ft_bzero(map, sizeof(t_map));
	map->copy_map = cpy_map(av[1]);
	if (!map->copy_map)
		return (1);
	map->after_map = after_path(map->copy_map, map);
	if (!map->after_map)
		return (free_full_map_data(map), 1);
	check_instruction(map);
	check_path(map);
	if (collect_data(map))
		return (free_full_map_data(map), 1);
	map_valid(map);
	map->mapp_scan = map_scan(map->after_map, av[1]);
	map->rectangular_map = rectangulare_map(map->mapp_scan, map);
	check_rectangle_map(map);
	search_position(map->rectangular_map, map);
	map->height = count_lines_tab(map->rectangular_map);
	return (0);
}

int main(int ac, char **av)
{
	t_map map;
	t_game game;

	if (parsing(ac, av, &map))
		return (1);
	// print_map(map.rectangular_map);
	init_game(&game, &map);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
