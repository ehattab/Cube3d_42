/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2026/01/15 16:53:18 by toroman          ###   ########.fr       */
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
		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO")
			|| !ft_strcmp(split_path[0], "WE") || !ft_strcmp(split_path[0],
				"EA"))
		{
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
		split_path = ft_split(beforemap[i], 32);
		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO")
			|| !ft_strcmp(split_path[0], "WE") || !ft_strcmp(split_path[0],
				"EA") || !ft_strcmp(split_path[0], "F")
			|| !ft_strcmp(split_path[0], "C"))
			c++;
		free_map(split_path);
		i++;
	}
	if (c != 6)
	{
		ft_error("error: instruction not correct\n", beforemap);
		exit(1);
	}
}

void	check_double(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_copy[i])
	{
		if (ft_strchr(map_copy[i], 'S') || ft_strchr(map_copy[i], 'N')
			|| ft_strchr(map_copy[i], 'W') || ft_strchr(map_copy[i], 'E'))
			j++;
		if (j > 1)
		{
			ft_error("error: Player has 2 positions\n", map_copy);
			exit(1);
		}
		i++;
	}
}

void	search_position(char **map_copy)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = -1;
	y = -1;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'S' || map_copy[i][j] == 'N'
				|| map_copy[i][j] == 'W' || map_copy[i][j] == 'E')
			{
				x = i;
				y = j;
			}
			j++;
		}
		i++;
	}
	error(x, y);
}

void	error(int x, int y)
{
	if (x == -1 || y == -1)
	{
		printf("error: no starting position found\n");
		exit(1);
	}
}
