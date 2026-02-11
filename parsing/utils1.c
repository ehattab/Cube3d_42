/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:16:45 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_len(char **map)
{
	int	i;
	int	len;
	int	big;

	i = 0;
	big = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > big)
			big = len;
		i++;
	}
	return (big);
}

char	**copy_map_data(char **map, char *argv)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (count_lines(argv) + 1));
	if (!map_copy)
		return (NULL);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_error(char *str, t_map *map)
{
	printf("Error\n%s", str);
	if (map)
		free_map_data(map);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_nums(char *str)
{
	int		i;
	char	**numbers;

	if (!str)
		return (1);
	numbers = ft_split(str, ',');
	if (!numbers)
		return (1);
	i = 0;
	while (numbers[i])
	{
		if (check_num(numbers[i]))
		{
			free_map(numbers);
			return (1);
		}
		i++;
	}
	free_map(numbers);
	return (0);
}
