/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:06 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_config(char *id)
{
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA")
		|| !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
		return (1);
	return (0);
}

int	process_line(char **cm, t_map *map, int *ij)
{
	char	*trim;
	char	**sc;
	int		ret;

	trim = ft_strtrim(cm[ij[0]], " \t\n\v\f\r");
	if (!trim || trim[0] == '\0')
		return (free(trim), 0);
	sc = ft_split(trim, ' ');
	ret = 0;
	if (sc && sc[0] && is_config(sc[0]))
	{
		map->before_map[ij[1]++] = ft_strdup(cm[ij[0]]);
		free_map(sc);
		return (free(trim), 0);
	}
	if (is_map(trim))
		ret = 1;
	if (sc)
		free_map(sc);
	free(trim);
	return (ret);
}

char	**split_config_map(char **copy_map, t_map *map)
{
	int	ij[2];

	ij[0] = 0;
	ij[1] = 0;
	map->before_map = malloc(sizeof(char *) * 100);
	if (!map->before_map)
		ft_error("Memory allocation failed\n", map);
	while (copy_map[ij[0]])
	{
		if (process_line(copy_map, map, ij))
			break ;
		ij[0]++;
	}
	map->before_map[ij[1]] = NULL;
	while (copy_map[ij[0]]
		&& (copy_map[ij[0]][0] == '\n' || copy_map[ij[0]][0] == '\0'))
		ij[0]++;
	extract_map(map, ij[0], copy_map);
	return (map->after_map);
}

void	extract_map(t_map *map, int i, char **copy_map)
{
	int	j;
	int	count;
	int	min_indent;

	count = 0;
	while (copy_map[i + count])
		count++;
	map->after_map = malloc(sizeof(char *) * (count + 1));
	if (!map->after_map)
		ft_error("Memory allocation failed\n", map);
	expand_map_tabs(&copy_map[i], count, map);
	min_indent = get_min_indent(&copy_map[i]);
	j = 0;
	while (copy_map[i])
	{
		map->after_map[j] = trim_line(copy_map[i], min_indent);
		j++;
		i++;
	}
	map->after_map[j] = NULL;
}

char	**remove_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				map[i][j] = '0';
				return (map);
			}
			j++;
		}
		i++;
	}
	return (map);
}
