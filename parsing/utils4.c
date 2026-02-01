/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:06 by toroman           #+#    #+#             */
/*   Updated: 2026/01/31 20:29:45 by ehattab          ###   ########.fr       */
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

char	**after_path(char **copy_map, t_map *map)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	j = 0;
	map->before_map = malloc(sizeof(char *) * 7);
	if (!map->before_map)
		return (NULL);
	while (copy_map[i] && j < 6)
	{
		trim = ft_strtrim(copy_map[i], " \t\n\v\f\r");
		if (trim && trim[0] != '\0')
			map->before_map[j++] = ft_strdup(copy_map[i]);
		free(trim);
		i++;
	}
	map->before_map[j] = NULL;
	while (copy_map[i] && (copy_map[i][0] == '\n' || copy_map[i][0] == '\0'))
		i++;
	copy_map_section(map, i, copy_map);
	return (map->after_map);
}

void	copy_map_section(t_map *map, int i, char **copy_map)
{
	int	j;
	int	count;

	count = 0;
	while (copy_map[i + count])
		count++;
	map->after_map = malloc(sizeof(char *) * (count + 1));
	if (!map->after_map)
		ft_error("malloc error\n", NULL);
	j = 0;
	while (copy_map[i])
	{
		map->after_map[j] = ft_strdup(copy_map[i]);
		j++;
		i++;
	}
	map->after_map[j] = NULL;
}
