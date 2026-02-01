/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2026/02/01 17:17:37 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/header/ft_printf.h"
# include "../utils/header/get_next_line.h"
# include "../utils/header/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_map
{
	char	**copy_map;
	char	**map_valide;
	char	**before_map;
	char	**after_map;
	char	**rectangular_map;
	char	**mapp_scan;
	char	**map_trim;
	char	*str_trim;
	int		big_len;
	int		i;
	int		j;
	int		new_len;
	int		start_x;
	int		start_y;
	int		height;
	int		length;
	int		no;
	int		so;
	int		ea;
	int		we;
	t_color	floor;
	t_color	ceiling;
	int		floor_hex;
	int		ceiling_hex;
}			t_map;


void		check_fd(int fd);
int			check_file(char *argv);
int			count_lines(char *argv);
void		print_map(char **argv);
int			check_space(char *str);
int			check_big_len(char **map);
char		**map_scan(char **map, char *argv);
void		ft_error(char *str, char **map);
void		free_map(char **map);
int			check_nums(char *str);
void		check_instruction(char **beforemap);
void		check_path(char **beforemap);
void		check_double(char **map_copy);
// void		error(int x, int y);
int			is_alpha(char *str);
int			check_xpm(char *str);
void		check_rgb(char *str);
void		check_c_f(char **split_str);
char		**rectangulare_map(char **copy_map, t_map *map);
char		**cpy_map(char *str);
int			check_char(char *copy_map);
void		map_valid(char **copy_map);
void		check(char **map);
void		check2(char **before_map);
int			paths(int c, t_map *map);
char		**after_path(char **copy_map, t_map *map);
void		copy_map_section(t_map *map, int i, char **copy_map);
void		check_rectangle_map(char **map);
void		check_map_hole(char **map, int i, int j);
int			parse_rgb(char *line, t_color *color);


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
