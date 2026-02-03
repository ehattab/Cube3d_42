/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:06 by toroman           #+#    #+#             */
/*   Updated: 2026/02/01 20:36:58 by ehattab          ###   ########.fr       */
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
	int		i;
	int		c[6];
	char	**split;

	i = -1;
	while (++i < 6)
		c[i] = 0;
	i = -1;
	while (before_map[++i])
	{
		split = ft_split(before_map[i], ' ');
		if (!split)
			ft_error("error: malloc fail in check2\n", before_map);
		if (split[0])
			count_identifiers(split, c);
		free_map(split);
	}
	validate_identifiers(c, before_map);
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

void	count_identifiers(char **split, int *c)
{
	if (ft_strcmp(split[0], "NO") == 0)
		c[0]++;
	else if (ft_strcmp(split[0], "SO") == 0)
		c[1]++;
	else if (ft_strcmp(split[0], "WE") == 0)
		c[2]++;
	else if (ft_strcmp(split[0], "EA") == 0)
		c[3]++;
	else if (ft_strcmp(split[0], "F") == 0)
		c[4]++;
	else if (ft_strcmp(split[0], "C") == 0)
		c[5]++;
}

void	validate_identifiers(int *c, char **before_map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (c[i] != 1)
			ft_error("error: duplicate or missing identifiers\n", before_map);
		i++;
	}
}
