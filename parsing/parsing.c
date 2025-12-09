/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:53:36 by toroman           #+#    #+#             */
/*   Updated: 2025/12/09 16:21:25 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**rectangulare_map(char **copy_map, t_map *map)
{
	char	*str;

	map->big_len = check_big_len(copy_map) + 1;
	map->i = 0;
	while (copy_map[map->i])
	{
		map->new_len = ft_strlen(copy_map[map->i]);
		str = malloc(sizeof(char) * (map->big_len + 1));
		map->j = 0;
		while(map->j < map->new_len)
		{
			if (copy_map[map->i][map->j] == ' ')
				str[map->j] = 'V';
			else
				str[map->j] = copy_map[map->i][map->j];
			map->j++;
		}
		while (map->j < map->big_len)
			str[map->j++] = 'V';
		str[map->big_len] = '\0';
		free(copy_map[map->i]);
		copy_map[map->i] = str;
		map->i++;
	}
	return (copy_map);
}
char	**cpy_map(char *str)
{
	int		fd;
	char	**copy_map;
	char	*line;
	int		i;

	copy_map = malloc(sizeof(char *) * (count_lines(str) + 1));
	fd = open(str, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while(line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] == '\0';
		copy_map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	copy_map[i] == NULL;
	close(fd);
	return (copy_map);
}

int	check_char(char *copy_map)
{
	int	i;

	i = 0;
	while (copy_map[i])
	{
		if (copy_map == ' ')
			i++;
		else if ((copy_map != '0' && copy_map[i] != '1')
			&& (copy_map[i] != 'N' && copy_map[i] != 'S') && (copy_map != 'E'
				&& copy_map[i] != 'W') && (copy_map[i] != '\t'
				&& copy_map[i] != '\0'))
			return (1);
		i++;
	}
	return (0);
}

void	map_valid(char **copy_map)
{
	int	i;

	i = 0;
	check_double(copy_map);
	search_position(copy_map);
	while(copy_map[i])
	{
		if (check_char(copy_map[i]) == 1)
		{
			ft_error("ERROR : invalid char inside map\n", &copy_map[i]);
			exit(1);
		}
		i++;
	}
}
