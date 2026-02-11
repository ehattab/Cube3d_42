/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:49:44 by tony              #+#    #+#             */
/*   Updated: 2026/02/11 20:11:51 by ehattab          ###   ########.fr       */
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
	char	**before_map;
	char	**after_map;
	char	**rectangular_map;
	char	**mapp_scan;
	int		big_len;
	int		i;
	int		j;
	int		new_len;
	int		start_x;
	int		start_y;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		floor_hex;
	int		ceiling_hex;
}			t_map;

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
	t_map		*map_data;
}				t_game;

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
	int		prev_map_x;
	int		map_x;
}	t_ray;

/*parsing*/
int			check_file(char *argv);
int			count_lines(char *argv);
int			count_tab_lines(char **tab);
void		replace_spaces(char **map_lines);
int			get_max_len(char **map);
char		**copy_map_data(char **map, char *argv);
void		ft_error(char *str, t_map *map);
void		free_map(char **map);
int			check_nums(char *str);
void		check_texture(char **sp, t_map *map);
int			is_texture(char *id);
void		check_path(t_map *map);
void		check_player_count(t_map *map);
void		find_player(char **map_copy, t_map *map);
int			check_num(char *num);
int			check_xpm(char *str);
int			check_rgb(char *str);
int			is_map(char *trimmed);
int			is_config(char *id);
int			process_line(char **cm, t_map *map, int *ij);
char		**split_config_map(char **copy_map, t_map *map);
void		extract_map(t_map *map, int i, char **copy_map);
char		**remove_player(char **map);
void		check_holes(t_map *map);
void		check_hole(t_map *map, int i, int j);
void		set_texture(t_map *map, char **split);
int			set_color(t_map *map, char **split);
int			parse_config(t_map *map);
char		*trim_line(char *line, int indent);
void		free_map_data(t_map *map);
void		validate_map(t_map *map);
int			find_first_char(char *line);
int			get_min_indent(char **map_lines);
void		count_configs(t_map *map, int *counts);
void		validate_config(t_map *map);
int			count_tabs(char *s);
void		expand_line(char *dst, char *src);
char		*expand_tabs(char *line);
void		expand_map_tabs(char **lines, int count, t_map *map);
char		*pad_line(char **copy_map, int i, t_map *map);
char		**make_rectangle(char **copy_map, t_map *map);
void		read_file_lines(int fd, char **copy_map, int *i, t_map *map);
char		**load_file(char *str, t_map *map);
int			check_char(char *copy_map);
int			build_hex(char *line, t_color *color);
int			parse_rgb(char *line, t_color *color);
int			parse_map_data(char **av, t_map *map);
int			parsing(int ac, char **av, t_map *map);

/*raycasting*/
void		put_pixel(int x, int y, int color, t_game *game);
void		draw_square(int *pos, int size, int color, t_game *game);
void		draw_map(t_game *game);
void		clear_image(t_game *game);
void		init_game(t_game *game, t_map *map);
bool		touch(float px, float py, t_game *game);
float		distance(float x, float y);
float		fixed_dist(float *p1, float *p2, t_game *game);
void		render_rays(t_game *game, t_player *player);
int			draw_loop(t_game *game);
void		init_player(t_player *player, t_map *map);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
bool		check_corner(float x, float y, t_game *game);
bool		can_move(float x, float y, t_game *game);
void		move_forward_backward(t_player *player, t_game *game, int dir);
void		move_left_right(t_player *player, t_game *game, int dir);
void		rotate_player(t_player *player);
void		move_player(t_player *player, t_game *game);
void		trace_ray(t_ray *ray, t_game *game);
void		cast_ray(t_ray *ray, t_player *pl, t_game *game, float angle);
void		draw_wall(t_game *game, t_ray *ray, int x);
void		draw_column(t_game *game, t_ray *ray, int x);
void		compute_wall(t_ray *ray);
void		init_texture_img(t_game *game, t_img *image, char *path);
void		load_textures(t_game *game, t_map *map);
t_img		*get_wall_texture(t_game *game, t_ray *ray);
float		spawn_angle(char p);
int			close_game(t_game *game);
void		draw_debug(t_game *game, t_player *player);

#endif
