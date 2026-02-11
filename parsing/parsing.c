/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:53:36 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*pad_line(char **copy_map, int i, t_map *map)
{
	char	*str;

	map->new_len = ft_strlen(copy_map[i]);
	str = malloc(sizeof(char) * (map->big_len + 1));
	if (!str)
		ft_error("Memory allocation failed\n", map);
	map->j = 0;
	while (map->j < map->big_len)
	{
		if (map->j < map->new_len)
			str[map->j] = copy_map[i][map->j];
		else
			str[map->j] = 'V';
		map->j++;
	}
	str[map->big_len] = '\0';
	return (str);
}

char	**make_rectangle(char **copy_map, t_map *map)
{
	char	*str;

	map->big_len = get_max_len(copy_map) + 1;
	map->i = 0;
	while (copy_map[map->i])
	{
		str = pad_line(copy_map, map->i, map);
		free(copy_map[map->i]);
		copy_map[map->i] = str;
		map->i++;
	}
	return (copy_map);
}

void	read_file_lines(int fd, char **copy_map, int *i, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		copy_map[*i] = ft_strdup(line);
		if (!copy_map[*i])
		{
			free(line);
			free_map(copy_map);
			close(fd);
			ft_error("Memory allocation failed\n", map);
		}
		free(line);
		(*i)++;
		line = get_next_line(fd);
	}
	copy_map[*i] = NULL;
}

char	**load_file(char *str, t_map *map)
{
	int		fd;
	char	**copy_map;
	int		i;

	if (!str)
		ft_error("Map file path is invalid\n", map);
	i = 0;
	copy_map = malloc(sizeof(char *) * (count_lines(str) + 1));
	if (!copy_map)
		ft_error("Memory allocation failed\n", map);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(copy_map);
		ft_error("Failed to open map file\n", map);
	}
	read_file_lines(fd, copy_map, &i, map);
	close(fd);
	return (copy_map);
}

int	check_char(char *line)
{
	int	i;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
