/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:10:29 by toroman           #+#    #+#             */
/*   Updated: 2025/12/09 17:29:47 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "cube3d.h"

 void	check_rectangle_map(char **map)
 {
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'V')
				check_map_hole(map, i, j);
			j++;
		}
		i++;
 	}
 }

 void	check_map_hole(char **map, int i, int j)
{
	if ((map[i + 1] && (map[i + 1][j] == '0'
		|| map[i + 1][j] == 'N' || map[i + 1][j] == 'S'
		|| map[i + 1][j] == 'E' || map[i + 1][j] == 'W'))
		|| (i > 0 && (map[i - 1][j] == '0' || map[i - 1][j] == 'N' 
		|| map[i - 1][j] == 'S' || map[i - 1][j] == 'E' || map[i - 1][j] == 'W'))
		|| (map[i][j + 1] && (map[i][j + 1] == '0' || map[i][j + 1] == 'N'
		|| map[i][j + 1] == 'S' || map[i][j + 1] == 'E' || map[i][j + 1] == 'W'))
		|| (j > 0 && (map[i][j - 1] == '0' || map[i][j - 1] == 'N' 
		|| map[i][j - 1] == 'S' || map[i][j - 1] == 'E' || map[i][j - 1] == 'W')))
	{
		ft_error("error: space found inside the map\n", map);
		exit(1);
	}
}
