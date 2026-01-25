/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:27 by toroman           #+#    #+#             */
/*   Updated: 2026/01/25 16:42:10 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z'))
			return (1);
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	check_xpm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str + ft_strlen(str) - 4, "xpm", 4))
			return (1);
	}
	return (0);
}

void	check_rgb(char *str)
{
	int		i;
	char	**split_str;

	i = 0;
	split_str = ft_split(str, ',');
	while (split_str[i])
		i++;
	if (i < 3 || i > 3)
	{
		printf("error: RGB is not right\n");
		free_map(split_str);
		exit(1);
	}
	free_map(split_str);
}

void	check_c_f(char **split_str)
{
	if (!ft_strcmp(split_str[0], "C") || !ft_strcmp(split_str[0], "F"))
	{
		if (check_nums(split_str[1]) == 1)
		{
			printf("error: RGB out of range\n");
			free_map(split_str);
			exit(1);
		}
		if (is_alpha(split_str[1]) == 1)
		{
			printf("error: numbers only\n");
			free_map(split_str);
			exit(1);
		}
		check_rgb(split_str[1]);
	}
	free_map(split_str);
}
