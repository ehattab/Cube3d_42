/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:00:00 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_line(char *line, int indent)
{
	int		end;
	char	*result;

	end = ft_strlen(line);
	while (end > indent && (line[end - 1] == '\n'))
		end--;
	if (indent >= end)
		return (ft_strdup(""));
	result = ft_substr(line, indent, end - indent);
	return (result);
}

void	free_map_data(t_map *map)
{
	if (!map)
		return ;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	free_map(map->copy_map);
	free_map(map->before_map);
	free_map(map->after_map);
	free_map(map->mapp_scan);
	if (map->rectangular_map && map->rectangular_map != map->mapp_scan)
		free_map(map->rectangular_map);
	ft_bzero(map, sizeof(t_map));
}

void	validate_map(t_map *map)
{
	int	i;

	if (!map->after_map)
		ft_error("Map data is missing\n", map);
	check_player_count(map);
	i = 0;
	while (map->after_map[i])
	{
		if (check_char(map->after_map[i]))
			ft_error("Map contains invalid characters\n", map);
		i++;
	}
}
