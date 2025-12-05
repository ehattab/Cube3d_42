/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2025/11/25 18:11:39 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../utils/header/ft_printf.h"
#include "../utils/header/get_next_line.h"
#include "../utils/header/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef	struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef	struct s_parsing
{
	char	**map_copy;
	int		width_copy;
};


void    check_fd(int fd);
int 	check_file(char *argv);
int 	count_lines(char *argv);
void    print_map(char **argv);
int 	check_space(char *str);
int		check_big_len(char **map);
char	**map_scan(char **map, char *argv);
void	ft_error(char *str, char **map);
void	free_map(char **map);
int		check_nums(char *str);
void	check_instruction(char **beforemap);
void	check_path(char **beforemap);
void	check_double(char **map_copy);
void	search_position(char **map_copy);
void	error(int x, int y);
int		is_alpha(char *str);
int		check_xpm(char *str);




#endif
