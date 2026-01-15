/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2026/01/15 18:05:28 by ehattab          ###   ########.fr       */
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
# define P_RADIUS 10


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

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	char		*data;
	int			endian;
	int			floor_color;
	int			ceil_color;
	char		**map;
	int			size_line;
	t_img		texture[4];
	t_player	player;
}				t_game;

typedef	struct s_gmap
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	char	p;
}			t_gmap;

typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	float	dir_x;
	float	dir_y;
	float	dist;
	float	line_height;
	int		draw_start;
	int		draw_end;
	int		side;
	float	wall_x;
}	t_ray;

void	search_position2(char **map_copy, t_gmap *map);
int		count_lines_tab(char **tab);


//Game
void	init_game(t_game *game, t_gmap *map);
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
void	init_player(t_player *player, t_gmap *map);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_player(t_player *player, t_game *game);
int		draw_loop(t_game *game);
void	clear_image(t_game *game);
char	**get_map(void);
void	draw_map(t_game *game);
bool	touch(float px, float py, t_game *game);
float	distance(float x, float y);
void	draw_column(t_game *game, t_ray *ray, int x);
float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game);
void	cast_ray(t_ray *ray, t_player *player, t_game *game, float angle);
void	compute_wall(t_ray *ray);
float	spawn_angle(char p);
char	**get_map1(void);
int		close_game(t_game *game);
bool	can_move(float x, float y, t_game *game);
void	init_texture_img(t_game *game, t_img *image, char *path);
void	load_textures(t_game *game);
t_img	*get_wall_texture(t_game *game, t_ray *ray);
void	draw_debug(t_game *game, t_player *player);

#endif