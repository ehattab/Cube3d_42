/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2026/01/31 18:41:43 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_path(char **beforemap)
{
	char	**split_path;
	int		i;
	int		fd;

	i = 0;
	while (beforemap[i])
	{
		split_path = ft_split(beforemap[i], ' ');
		if (!split_path)
			ft_error("malloc error\n", beforemap);

		if (!ft_strcmp(split_path[0], "NO")
			|| !ft_strcmp(split_path[0], "SO")
			|| !ft_strcmp(split_path[0], "WE")
			|| !ft_strcmp(split_path[0], "EA"))
		{
			if (!split_path[1])
			{
				free_map(split_path);
				ft_error("error: invalid texture path\n", beforemap);
			}
			fd = open(split_path[1], O_RDONLY);
			if (fd == -1)
			{
				free_map(split_path);
				ft_error("error: path not found\n", beforemap);
			}
			close(fd);
		}
		free_map(split_path);
		i++;
	}
}

void	check_instruction(char **beforemap)
{
	int		i;
	int		c;
	char	**split_path;

	i = 0;
	c = 0;
	while (beforemap[i])
	{
		split_path = ft_split(beforemap[i], ' ');
		if (!split_path)
			ft_error("malloc error\n", beforemap);

		if (!ft_strcmp(split_path[0], "NO")
			|| !ft_strcmp(split_path[0], "SO")
			|| !ft_strcmp(split_path[0], "WE")
			|| !ft_strcmp(split_path[0], "EA")
			|| !ft_strcmp(split_path[0], "F")
			|| !ft_strcmp(split_path[0], "C"))
			c++;
		free_map(split_path);
		i++;
	}
	if (c != 6)
		ft_error("error: instruction not correct\n", beforemap);
}

void	check_double(char **map_copy)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N'
				|| map_copy[i][j] == 'S'
				|| map_copy[i][j] == 'E'
				|| map_copy[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_error("Error\nMap must have exactly one player position\n",
			map_copy);
}

void	search_position2(char **map_copy, t_gmap *gmap)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N'
				|| map_copy[i][j] == 'S'
				|| map_copy[i][j] == 'E'
				|| map_copy[i][j] == 'W')
			{
				gmap->y = i;
				gmap->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_lines_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
