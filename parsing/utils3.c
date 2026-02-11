/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:27 by toroman           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_num(char *num)
{
	int	j;
	int	value;

	j = 0;
	while (num[j])
	{
		if (!ft_isdigit(num[j]) && num[j] != '\n')
			return (1);
		j++;
	}
	if (j == 0)
		return (1);
	value = ft_atoi(num);
	if (value < 0 || value > 255)
		return (1);
	return (0);
}

int	check_xpm(char *str)
{
	int	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	if (len < 4)
		return (1);
	if (ft_strncmp(str + len - 4, ".xpm", 4))
		return (1);
	return (0);
}

int	check_rgb(char *str)
{
	int		i;
	char	**split_str;

	if (!str)
		return (1);
	split_str = ft_split(str, ',');
	if (!split_str)
		return (1);
	i = 0;
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

int	is_map(char *trimmed)
{
	int	k;

	if (!trimmed || !trimmed[0])
		return (0);
	k = 0;
	while (trimmed[k])
	{
		if (trimmed[k] != '0' && trimmed[k] != '1'
			&& trimmed[k] != 'N' && trimmed[k] != 'S'
			&& trimmed[k] != 'E' && trimmed[k] != 'W'
			&& trimmed[k] != ' ' && trimmed[k] != '\t')
			return (0);
		k++;
	}
	return (1);
}
