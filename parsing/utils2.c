/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture(char **sp, t_map *map)
{
	int	fd;

	if (!sp[1])
	{
		free_map(sp);
		ft_error("Texture path is missing\n", map);
	}
	if (check_xpm(sp[1]))
	{
		free_map(sp);
		ft_error("Texture file must have .xpm extension\n", map);
	}
	fd = open(sp[1], O_RDONLY);
	if (fd == -1)
	{
		free_map(sp);
		ft_error("Failed to open texture file\n", map);
	}
	close(fd);
}

int	is_texture(char *id)
{
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA"))
		return (1);
	return (0);
}

void	check_path(t_map *map)
{
	char	**sp;
	int		i;

	i = 0;
	while (map->before_map[i])
	{
		sp = ft_split(map->before_map[i], ' ');
		if (!sp)
			ft_error("Memory allocation failed\n", map);
		if (is_texture(sp[0]))
			check_texture(sp, map);
		free_map(sp);
		i++;
	}
}

void	check_player_count(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->after_map[i])
	{
		j = 0;
		while (map->after_map[i][j])
		{
			if (map->after_map[i][j] == 'N' || map->after_map[i][j] == 'S'
				|| map->after_map[i][j] == 'E'
				|| map->after_map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_error("Map must contain exactly one player start\n", map);
}

void	find_player(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N' || map_copy[i][j] == 'S'
				|| map_copy[i][j] == 'E' || map_copy[i][j] == 'W')
			{
				map->start_y = i;
				map->start_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
