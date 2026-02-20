/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:10:29 by toroman           #+#    #+#             */
/*   Updated: 2026/02/16 21:41:57 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_holes(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->rectangular_map[i])
	{
		j = 0;
		while (map->rectangular_map[i][j])
		{
			if (map->rectangular_map[i][j] == 'V')
				check_hole(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_hole(t_map *map, int i, int j)
{
	char	**m;

	m = map->rectangular_map;
	if ((m[i + 1] && (m[i + 1][j] == '0' || m[i + 1][j] == 'N'
		|| m[i + 1][j] == 'S' || m[i + 1][j] == 'E'
		|| m[i + 1][j] == 'W'))
		|| (i > 0 && (m[i - 1][j] == '0' || m[i - 1][j] == 'N'
		|| m[i - 1][j] == 'S' || m[i - 1][j] == 'E'
		|| m[i - 1][j] == 'W'))
		|| (m[i][j + 1] && (m[i][j + 1] == '0' || m[i][j + 1] == 'N'
		|| m[i][j + 1] == 'S' || m[i][j + 1] == 'E'
		|| m[i][j + 1] == 'W'))
		|| (j > 0 && (m[i][j - 1] == '0' || m[i][j - 1] == 'N'
		|| m[i][j - 1] == 'S' || m[i][j - 1] == 'E'
		|| m[i][j - 1] == 'W')))
		ft_error("Map has holes or is not closed\n", map);
}

void	set_texture(t_map *map, char **split)
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

int	set_color(t_map *map, char **split)
{
	t_color	tmp_color;
	int		hex;

	if (ft_strcmp(split[0], "F") == 0)
	{
		hex = parse_rgb(split[1], &tmp_color);
		if (hex == -1)
			return (1);
		map->floor_hex = hex;
	}
	else if (ft_strcmp(split[0], "C") == 0)
	{
		hex = parse_rgb(split[1], &tmp_color);
		if (hex == -1)
			return (1);
		map->ceiling_hex = hex;
	}
	return (0);
}

int	parse_config(t_map *map)
{
	int		i;
	char	**split;

	i = 0;
	while (map->before_map && map->before_map[i])
	{
		split = ft_split(map->before_map[i], ' ');
		if (!split)
			return (1);
		if (!split[0] || !split[1])
		{
			printf("Error\nConfig line missing value\n");
			free_map(split);
			return (1);
		}
		set_texture(map, split);
		if (set_color(map, split))
		{
			free_map(split);
			return (1);
		}
		free_map(split);
		i++;
	}
	return (0);
}
