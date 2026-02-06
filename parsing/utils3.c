/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:27 by toroman           #+#    #+#             */
/*   Updated: 2026/02/06 19:33:36 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	check_xpm(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str + ft_strlen(str) - 4, "xpm", 4))
			return (1);
	}
	return (0);
}

int	check_rgb(char *str)
{
	int		i;
	char	**split_str;

	i = 0;
	split_str = ft_split(str, ',');
	while (split_str[i])
		i++;
	if (i != 3)
	{
		free_map(split_str);
		return (1);
	}
	free_map(split_str);
	return (0);
}

void	check_c_f(char **split_str, t_map *map)
{
	if (!ft_strcmp(split_str[0], "C") || !ft_strcmp(split_str[0], "F"))
	{
		if (check_nums(split_str[1]) == 1)
		{
			free_map(split_str);
			ft_error("RGB out of range\n", map);
		}
		if (is_alpha(split_str[1]) == 1)
		{
			free_map(split_str);
			ft_error("numbers only\n", map);
		}
		check_rgb(split_str[1]);
	}
	free_map(split_str);
}
