/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2025/12/09 17:31:12 by toroman          ###   ########.fr       */
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

typedef struct s_map
{
	char		**copy_map;
	char		**map_valide;
	char		**before_map;
	char		**after_map;
	char		**rectangular_map;
	char		**mapp_scan;
	char		**map_trim;
	char		*str_trim;
	int			big_len;
	int			i;
	int			j;
	int			new_len;
	int			start_x;
	int			start_y;
	int			height;
	int			length;
	int			NO;
	int			SO;
	int			EA;
	int			WE;
}				t_map;


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
void	check_rgb(char *str);
void	check_c_f(char **split_str);
char	**rectangulare_map(char **copy_map, t_map *map);
char	**cpy_map(char *str);
int		check_char(char *copy_map);
void	map_valid(char **copy_map);
void	check(char **map);
void	check2(char **before_map);
int		paths(int c, t_map *map);
char	**after_path(char **copy_map, char av, t_map *map);
void	copy_map_section(t_map *map, int i, char *av, char **copy_map);
void	check_rectangle_map(char **map);
void	check_map_hole(char **map, int i, int j);

#endif
