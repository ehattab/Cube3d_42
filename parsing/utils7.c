/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:07:46 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/11 21:51:37 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_mixed_ws_line(char *line)
{
	int	i;
	int	has_tab;
	int	has_space;
	int	first_char;

	i = 0;
	has_tab = 0;
	has_space = 0;
	first_char = 0;
	while (line[i] && !first_char)
	{
		if (line[i] == '\t')
			has_tab = 1;
		else if (line[i] == ' ')
			has_space = 1;
		else if (line[i] != '\n')
			first_char = 1;
		i++;
	}
	return (has_tab && has_space);
}

int	check_mixed_ws(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (check_mixed_ws_line(lines[i]))
			return (1);
		i++;
	}
	return (0);
}

int	find_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (999999);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			return (i);
		i++;
	}
	return (999999);
}

int	get_min_indent(char **map_lines)
{
	int	i;
	int	min_indent;
	int	current_indent;

	min_indent = 999999;
	i = 0;
	while (map_lines[i])
	{
		current_indent = find_first_char(map_lines[i]);
		if (current_indent < min_indent)
			min_indent = current_indent;
		i++;
	}
	if (min_indent == 999999)
		return (0);
	return (min_indent);
}
