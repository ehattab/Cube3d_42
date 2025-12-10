/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:27 by toroman           #+#    #+#             */
/*   Updated: 2025/12/10 17:51:15 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_alpha(char *str)
{
	int	i;

	i = 0;
	while(str[i])
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
	
	while(str[i])
	{
		if (ft_strncmp(str + ft_strlen(str) - 4, "xpm", 4))
			return (1);
	}
	return (0);
}
