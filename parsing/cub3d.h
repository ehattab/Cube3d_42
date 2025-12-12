/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2025/12/12 22:30:13 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../utils/header/ft_printf.h"
#include "../utils/header/get_next_line.h"
#include "../utils/header/libft.h"
#include "../utils/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 0

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define PI 3.14159265359

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	char		**map;
}				t_game;

typedef	struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	char	p;
}			t_map;

// typedef	struct s_parsing
// {
// 	char	**map_copy;
// 	int		width_copy;
// };


// void	check_fd(int fd);
// int		check_file(char *argv);
// int		count_lines(char *argv);
// void	print_map(char **argv);
// int		check_space(char *str);
// int		check_big_len(char **map);
// char	**map_scan(char **map, char *argv);
// void	ft_error(char *str, char **map);
// void	free_map(char **map);
// int		check_nums(char *str);
// void	check_instruction(char **beforemap);
// void	check_path(char **beforemap);
// void	check_double(char **map_copy);
void	search_position(char **map_copy, t_map *map);
int		count_lines_tab(char **tab);
// void	error(int x, int y);
// int		is_alpha(char *str);
// int		check_xpm(char *str);

//Game
void	init_game(t_game *game, t_map *map);
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	init_player(t_player *player, t_map *map);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_player(t_player *player);
int		draw_loop(t_game *game);
void	clear_image(t_game *game);
char	**get_map(void);
void	draw_map(t_game *game);
bool	touch(float px, float py, t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
float	distance(float x, float y);
float	spawn_angle(char p);
char	**get_map1(void);
int		close_game(t_game *game);

#endif