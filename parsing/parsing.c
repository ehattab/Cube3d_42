/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:53:36 by toroman           #+#    #+#             */
/*   Updated: 2026/02/06 18:32:48 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**rectangulare_map(char **copy_map, t_map *map)
{
	char *str;

	map->big_len = check_big_len(copy_map) + 1;
	map->i = 0;
	while (copy_map[map->i])
	{
		map->new_len = ft_strlen(copy_map[map->i]);
		str = malloc(sizeof(char) * (map->big_len + 1));
		if (!str)
			ft_error("malloc error\n", map);
		map->j = 0;
		while (map->j < map->big_len)
		{
			if (map->j < map->new_len && copy_map[map->i][map->j] != ' ')
				str[map->j] = copy_map[map->i][map->j];
			else
				str[map->j] = 'V';
			map->j++;
		}
		str[map->big_len] = '\0';
		free(copy_map[map->i]);
		copy_map[map->i] = str;
		map->i++;
	}
	return (copy_map);
}

char	**cpy_map(char *str)
{
	int fd;
	char **copy_map;
	char *line;
	int i;

	if (!str)
		return (NULL);
	i = 0;
	copy_map = malloc(sizeof(char *) * (count_lines(str) + 1));
	if (!copy_map)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(copy_map);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		copy_map[i] = ft_strdup(line);
		if (!copy_map[i])
		{
			free(line);
			free_map(copy_map);
			close(fd);
			return (NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	copy_map[i] = NULL;
	close(fd);
	return (copy_map);
}

int	check_char(char *line)
{
	int i;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' &&
			line[i] != 'S' && line[i] != 'E' && line[i] != 'W' &&
			line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	map_valid(t_map *map)
{
	int i;

	if (!map->after_map)
		ft_error("Map is NULL\n", map);
	check_double(map);
	i = 0;
	while (map->after_map[i])
	{
		if (check_char(map->after_map[i]))
			ft_error("invalid char inside map\n", map);
		i++;
	}
}
