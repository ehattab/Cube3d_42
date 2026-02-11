/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:51:41 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 21:56:32 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *argv)
{
	int	len;

	if (!argv)
	{
		printf("Error\nMap file path is invalid\n");
		return (1);
	}
	len = ft_strlen(argv);
	if (len < 5)
	{
		printf("Error\nMap file name is too short\n");
		return (1);
	}
	if (ft_strncmp(argv + len - 4, ".cub", 4))
	{
		printf("Error\nMap file must end with .cub\n");
		return (1);
	}
	return (0);
}

int	count_lines(char *argv)
{
	int		i;
	int		fd;
	char	*lines;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = get_next_line(fd);
	while (lines)
	{
		i++;
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	count_tab_lines(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	replace_spaces(char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map_lines[i])
	{
		j = 0;
		while (map_lines[i][j])
		{
			if (map_lines[i][j] == ' ')
				map_lines[i][j] = '0';
			j++;
		}
		i++;
	}
}
