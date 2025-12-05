/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:16:45 by toroman           #+#    #+#             */
/*   Updated: 2025/11/18 18:01:03 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_big_len(char **map)
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

char	**map_scan(char **map, char *argv)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (count_lines(argv) - 6) + 1);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_error(char *str, char **map)
{
	printf("%s", str);
	if (map != NULL)
		free_map(map);
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
	int		integer;

	numbers = ft_split(str, ',');
	i = 0;
	while (numbers[i])
	{
		integer = ft_atoi(numbers[i]);
		if (integer < 0 || integer > 255)
		{
			free_map(numbers);
			return (1);
		}
		i++;
	}
	free_map(numbers);
	return (0);
}
