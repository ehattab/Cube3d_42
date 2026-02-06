/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2026/02/06 19:29:49 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_path(t_map *map)
{
	char **split_path;
	int i;
	int fd;

	i = 0;
	while (map->before_map[i])
	{
		split_path = ft_split(map->before_map[i], ' ');
		if (!split_path)
			ft_error("malloc error\n", map);
		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO") || !ft_strcmp(split_path[0], "WE") || !ft_strcmp(split_path[0], "EA"))
		{
			if (!split_path[1])
			{
				free_map(split_path);
				ft_error("invalid texture path\n", map);
			}
			fd = open(split_path[1], O_RDONLY);
			if (fd == -1)
			{
				free_map(split_path);
				ft_error("path not found\n", map);
			}
			close(fd);
		}
		free_map(split_path);
		i++;
	}
}

void check_instruction(t_map *map)
{
	int i;
	int c;
	char **split_path;

	i = 0;
	c = 0;
	while (map->before_map[i])
	{
		split_path = ft_split(map->before_map[i], ' ');
		if (!split_path)
			ft_error("malloc error\n", map);
		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO") || !ft_strcmp(split_path[0], "WE") || !ft_strcmp(split_path[0], "EA") || !ft_strcmp(split_path[0], "F") || !ft_strcmp(split_path[0], "C"))
			c++;
		free_map(split_path);
		i++;
	}
	if (c != 6)
		ft_error("Instruction not correct\n", map);
}

void check_double(t_map *map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map->after_map[i])
	{
		j = 0;
		while (map->after_map[i][j])
		{
			if (map->after_map[i][j] == 'N' || map->after_map[i][j] == 'S' || map->after_map[i][j] == 'E' || map->after_map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_error("Map must have exactly one player position\n", map);
}

void search_position(char **map_copy, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N' || map_copy[i][j] == 'S' || map_copy[i][j] == 'E' || map_copy[i][j] == 'W')
			{
				map->start_y = i;
				map->start_x = j;
				return;
			}
			j++;
		}
		i++;
	}
}

int count_lines_tab(char **tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
