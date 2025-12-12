/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:43 by toroman           #+#    #+#             */
/*   Updated: 2025/12/12 16:31:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
				map->x = i;
				map->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
