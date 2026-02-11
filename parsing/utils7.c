/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:00:00 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 20:04:00 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			return (i);
		i++;
	}
	return (999999);
}

int	get_min_indent(char **map_lines)
{
	int	i;
	int	min_indent;
	int	current_indent;

	min_indent = 999999;
	i = 0;
	while (map_lines[i])
	{
		current_indent = find_first_char(map_lines[i]);
		if (current_indent < min_indent)
			min_indent = current_indent;
		i++;
	}
	if (min_indent == 999999)
		return (0);
	return (min_indent);
}

void	count_configs(t_map *map, int *counts)
{
	int		i;
	char	**sp;

	i = 0;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	while (map->before_map[i])
	{
		sp = ft_split(map->before_map[i], ' ');
		if (!sp)
			ft_error("Memory allocation failed\n", map);
		if (is_texture(sp[0]))
			counts[0]++;
		else if (!ft_strcmp(sp[0], "F"))
			counts[1]++;
		else if (!ft_strcmp(sp[0], "C"))
			counts[2]++;
		free_map(sp);
		i++;
	}
}

void	validate_config(t_map *map)
{
	int	counts[3];

	count_configs(map, counts);
	if (counts[1] != 1 || counts[2] != 1)
		ft_error("Floor and ceiling must be defined once\n", map);
	if (counts[0] != 4
		|| counts[1] + counts[2] + counts[0] != 6)
		ft_error("Config must have NO, SO, WE, EA, F, C once\n", map);
}
