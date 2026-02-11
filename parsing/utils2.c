/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:31:06 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 21:50:50 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(char *id)
{
	if (!id)
		return (0);
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA"))
		return (1);
	return (0);
}

void	check_texture(char **sp, t_map *map)
{
	if (!sp || !sp[0] || !sp[1])
		ft_error("Invalid texture configuration\n", map);
	if (!is_texture(sp[0]))
		return ;
	if (sp[2])
		ft_error("Too many arguments for texture path\n", map);
	if (check_xpm(sp[1]))
		ft_error("Texture file must be .xpm format\n", map);
}

void	check_path(t_map *map)
{
	int	fd;

	if (!map->no_path || !map->so_path || !map->we_path || !map->ea_path)
		ft_error("Missing texture path(s)\n", map);
	fd = open(map->no_path, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open NO texture file\n", map);
	close(fd);
	fd = open(map->so_path, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open SO texture file\n", map);
	close(fd);
	fd = open(map->we_path, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open WE texture file\n", map);
	close(fd);
	fd = open(map->ea_path, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open EA texture file\n", map);
	close(fd);
}

void	check_player_count(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map->after_map[i])
	{
		j = 0;
		while (map->after_map[i][j])
		{
			if (map->after_map[i][j] == 'N' || map->after_map[i][j] == 'S'
				|| map->after_map[i][j] == 'E' || map->after_map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_error("Map must have exactly one player position\n", map);
	if (count > 1)
		ft_error("Map cannot have multiple player positions\n", map);
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
				map->start_x = j;
				map->start_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_error("Player position not found in map\n", map);
}
