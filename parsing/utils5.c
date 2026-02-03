/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:10:29 by toroman           #+#    #+#             */
/*   Updated: 2026/02/01 20:08:51 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rectangle_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'V')
				check_map_hole(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_map_hole(char **map, int i, int j)
{
	if ((map[i + 1] && (map[i + 1][j] == '0' || map[i + 1][j] == 'N' || map[i
			+ 1][j] == 'S' || map[i + 1][j] == 'E' || map[i + 1][j] == 'W'))
		|| (i > 0 && (map[i - 1][j] == '0' || map[i - 1][j] == 'N' || map[i
				- 1][j] == 'S' || map[i - 1][j] == 'E' || map[i - 1][j] == 'W'))
		|| (map[i][j + 1] && (map[i][j + 1] == '0' || map[i][j + 1] == 'N'
				|| map[i][j + 1] == 'S' || map[i][j + 1] == 'E' || map[i][j
				+ 1] == 'W')) || (j > 0 && (map[i][j - 1] == '0' || map[i][j
				- 1] == 'N' || map[i][j - 1] == 'S' || map[i][j - 1] == 'E'
				|| map[i][j - 1] == 'W')))
	{
		ft_error("error: space found inside the map\n", map);
		exit(1);
	}
}

void	assign_texture(t_map *map, char **split)
{
	if (ft_strcmp(split[0], "NO") == 0)
		map->no_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		map->so_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		map->we_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		map->ea_path = ft_strdup(split[1]);
}

void	assign_color(t_map *map, char **split)
{
	t_color	tmp_color;

	if (ft_strcmp(split[0], "F") == 0)
		map->floor_hex = parse_rgb(split[1], &tmp_color);
	else if (ft_strcmp(split[0], "C") == 0)
		map->ceiling_hex = parse_rgb(split[1], &tmp_color);
}

int	collect_data(t_map *map)
{
	int		i;
	char	**split;

	i = 0;
	while (map->before_map && map->before_map[i])
	{
		split = ft_split(map->before_map[i], ' ');
		if (!split)
			return (1);
		if (split[0] && split[1])
		{
			assign_texture(map, split);
			assign_color(map, split);
		}
		free_map(split);
		i++;
	}
	return (0);
}

void	free_parsing_data(t_map *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
}