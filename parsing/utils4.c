/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:06 by toroman           #+#    #+#             */
/*   Updated: 2026/01/15 16:52:58 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				x++;
			j++;
		}
		i++;
	}
	if (x > 1)
	{
		ft_error("ERROR: player has 2 positions\n", map);
		exit(1);
	}
}

void	check2(char **before_map)
{
	t_map	map;
	int		i;
	char	**split;

	map = (t_map){0};
	i = 0;
	while (before_map[i])
	{
		split = ft_split(before_map[i], ' ');
		if (!ft_strcmp(split[0], "NO"))
			map.no++;
		if (!ft_strcmp(split[0], "SO"))
			map.so++;
		if (!ft_strcmp(split[0], "EA"))
			map.ea++;
		if (!ft_strcmp(split[0], "WE"))
			map.we++;
		free_map(split);
		i++;
	}
	if (map.no > 1 || map.so > 1 || map.ea > 1 || map.we > 1)
	{
		ft_error("error: coordinates not found\n", before_map);
		exit(1);
	}
}

int	paths(int c, t_map *map)
{
	if (c == 6)
	{
		free(map->str_trim);
		return (1);
	}
	return (0);
}

char	**after_path(char **copy_map, char *av, t_map *map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	map->before_map = malloc(sizeof(char *) * 7);
	while (copy_map[i])
	{
		map->str_trim = ft_strtrim(copy_map[i], "\t\n\f\r\v");
		if (map->str_trim && map->str_trim[0] != '\0')
		{
			map->before_map[j] = copy_map[i];
			j++;
			x++;
		}
		if (paths(x, map) == 1)
			break ;
		i++;
		free(map->str_trim);
	}
	copy_map_section(map, i, av, copy_map);
	return (map->after_map);
}

void	copy_map_section(t_map *map, int i, char *av, char **copy_map)
{
	int	j;

	map->after_map = malloc(sizeof(char *) * ((count_lines(av) - 6) + 1));
	j = 0;
	i++;
	while (copy_map[i])
	{
		map->after_map[j] = copy_map[i];
		j++;
		i++;
	}
	map->after_map[j] = NULL;
}
