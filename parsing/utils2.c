/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2025/12/12 21:57:01 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	check_path(char **beforemap)
// {
// 	char	**split_path;
// 	int		i;

// 	i = 0;
// 	while(beforemap[i])
// 	{
// 		split_path = ft_split(beforemap[i], 32);
// 		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO")
// 			|| !ft_strcmp(split_path[0],"WE") || !ft_strcmp(split_path[0], "EA"))
// 		{
// 			if (open(split_path[1], O_RDONLY == -1))
// 			{
// 				ft_error("error: path not found\n", beforemap);
// 				free_map(split_path);
// 				exit(1);
// 			}
// 		}
// 	}
// 	i++;
// }

// void	check_instruction(char **beforemap)
// {
// 	int	i;
// 	int	c;
// 	char	**split_path;

// 	i = 0;
// 	c = 0;
// 	while(beforemap[i])
// 	{
// 		split_path = ft_split(beforemap[i], 32);
// 		if (!ft_strcmp(split_path[0], "NO") || !ft_strcmp(split_path[0], "SO")
// 			|| !ft_strcmp(split_path[0], "WE") || !ft_strcmp(split_path[0], "EA"))
// 			c++;
// 		free_map(split_path);
// 		i++;
// 	}
// 	if (c != 6)
// 	{
// 		ft_error("error: instruction not correct\n", beforemap);
// 		exit (1);
// 	}
// }

// void	check_double(char **map_copy)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while(map_copy[i])
// 	{
// 		if (ft_strchr(map_copy[i], "S") || ft_strchr(map_copy[i], "N")
// 			|| ft_strchr(map_copy[i], "W") || ft_strchr(map[i], "E"))
// 			c++;
// 		if (j > 1)
// 		{
// 			ft_error("error: PLayer has 2 positions\n", map_copy);
// 			exit (1);
// 		}
// 		i++;
// 	}
// }

void	search_position(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(map_copy[i])
	{
		j = 0;
		while(map_copy[i][j])
		{
			if (map_copy[i][j] == 'S' || map_copy[i][j] == 'N'
				|| map_copy[i][j] == 'W' || map_copy[i][j] == 'E')
			{
				map->y = i;
				map->x = j;
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
