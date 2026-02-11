/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:13:12 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 21:52:04 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_tabs(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

void	expand_line(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\t')
		{
			dst[j++] = ' ';
			dst[j++] = ' ';
			dst[j++] = ' ';
			dst[j++] = ' ';
		}
		else
			dst[j++] = src[i];
		i++;
	}
	dst[j] = '\0';
}

char	*expand_tabs(char *line)
{
	int		tabs;
	int		new_len;
	char	*result;

	tabs = count_tabs(line);
	if (tabs == 0)
		return (ft_strdup(line));
	new_len = ft_strlen(line) + (tabs * 3);
	result = malloc(sizeof(char) * (new_len + 1));
	if (!result)
		return (NULL);
	expand_line(result, line);
	return (result);
}

void	expand_map_tabs(char **lines, int count, t_map *map)
{
	int		i;
	char	*expanded;

	i = 0;
	while (i < count)
	{
		expanded = expand_tabs(lines[i]);
		if (!expanded)
			ft_error("Memory allocation failed\n", map);
		free(lines[i]);
		lines[i] = expanded;
		i++;
	}
}
