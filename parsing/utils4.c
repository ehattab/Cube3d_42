/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:06 by toroman           #+#    #+#             */
/*   Updated: 2026/02/06 19:29:14 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**after_path(char **copy_map, t_map *map)
{
	int i;
	int j;
	char *trim;

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
	int j;
	int count;

	count = 0;
	while (copy_map[i + count])
		count++;
	map->after_map = malloc(sizeof(char *) * (count + 1));
	if (!map->after_map)
		ft_error("malloc error\n", map);
	j = 0;
	while (copy_map[i])
	{
		map->after_map[j] = ft_strdup(copy_map[i]);
		j++;
		i++;
	}
	map->after_map[j] = NULL;
}

char **replace_player_with_zero(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
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

void	free_full_map_data(t_map *map)
{
	if (!map)
		return;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->copy_map)
		free_map(map->copy_map);
	if (map->before_map)
		free_map(map->before_map);
	if (map->after_map)
		free_map(map->after_map);
	if (map->mapp_scan)
		free_map(map->mapp_scan);
	if (map->rectangular_map && map->rectangular_map != map->mapp_scan)
		free_map(map->rectangular_map);
	ft_bzero(map, sizeof(t_map));
}
