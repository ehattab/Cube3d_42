/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2026/01/25 16:43:47 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int ac, char **av, t_map *map)
{
	if (ac == 2 && check_file(av[1]) == 0)
	{
		map->copy_map = cpy_map(av[1]);
		after_path(map->copy_map, av[1], map);
		check_instruction(map->before_map);
		check_path(map->before_map);
		map_valid(map->after_map);
		map->mapp_scan = map_scan(map->copy_map, av[1]);
		map->rectangular_map = rectangulare_map(map->mapp_scan, map);
		check_rectangle_map(map->rectangular_map);
	}
	else
	{
		printf("ERROR: path is needed\n");
		return (1);
	}
	return (0);
}
void	replace_player_with_zero(char **map, t_map *map_struct)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (map[i] && !found)
	{
		j = 0;
		while (map[i][j] && !found)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				map_struct->start_x = i;
				map_struct->start_y = j;
				map[i][j] = '0';
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (!found)
		ft_error("error: no starting position found\n", map);
}

int	parse_rgb(char *line, t_color *color)
{
	char	**split;
	int		hex;

	if (!line)
	{
		printf("Error\nInvalid RGB line\n");
		exit(1);
	}
	check_rgb(line);
	split = ft_split(line, ',');
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		printf("Error\nRGB values must be between 0 and 255\n");
		free_map(split);
		exit(1);
	}
	hex = (color->r << 16) | (color->g << 8) | color->b;
	free_map(split);
	return (hex);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (1);
	ft_bzero(&map, sizeof(t_map));
	// --- Parsing minimal ---
	printf("Step 1: Reading file...\n");
	map.copy_map = cpy_map(av[1]); // lire le fichier
	printf("Step 2: Separating instructions...\n");
	map.after_map = after_path(map.copy_map, av[1], &map);
	// séparer instructions / map
	printf("Step 3: Validating map...\n");
	map_valid(map.after_map); // vérifie les caractères
	printf("Step 4: Scanning map...\n");
	map.mapp_scan = map_scan(map.after_map, av[1]); // copie de la map
	printf("Step 5: Making rectangular...\n");
	map.rectangular_map = rectangulare_map(map.mapp_scan, &map);
	// rectangulaire
	printf("Step 6: Checking rectangle...\n");
	check_rectangle_map(map.rectangular_map); // vérifie trous / espaces
	printf("✅ Parsing OK\n");
	// --- Free ---
	// Note: map.after_map and map.before_map are arrays of pointers to copy_map strings
	// We need to free the arrays themselves, but NOT the strings they point to
	if (map.before_map)
		free(map.before_map);
	if (map.after_map)
		free(map.after_map);
	free_map(map.copy_map);
	free_map(map.rectangular_map);
	printf("🟢 End of test\n");
	return (0);
}
