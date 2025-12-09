/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2025/12/09 17:33:13 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	parsing(int ac, char **av, t_map *map)
{
	if (ac == 2 && check_file(av[1]) == 0)
	{
		map->copy_map = cpy_map(av[1]);
		check_instruction(map->before_map);
		check_path(map->before_map);
		map_valid(map->map_valide);
		map->mapp_scan = map_scan(map_valid, av[1]);
		map->rectangular_map = rectangulare_map(map->mapp_scan, map);
		check_rectangle_map(map->rectangular_map);
		map->height = raycasting;
	}
	else
	{
		printf("ERROR: path is needed\n");
		return(1);
	}
	return (0);
}
