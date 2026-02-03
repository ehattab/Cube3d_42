/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:13 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/02 18:18:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

void	init_texture_img(t_game *game, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(game->mlx, path,
	&image->width, &image->height);
	if (!image->img)
	{
		printf("Error\nTexture not found: %s\n", path);
		exit(1);
	}
	image->data = mlx_get_data_addr(image->img, &image->bpp,
	&image->size_line, &image->endian);
}

void	load_textures(t_game *game, t_map *map)
{
	init_texture_img(game, &game->texture[0], map->no_path); //N
	init_texture_img(game, &game->texture[1], map->so_path); //S
	init_texture_img(game, &game->texture[2], map->we_path); //W
	init_texture_img(game, &game->texture[3], map->ea_path); //E
}

t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->texture[3]);
		else
			return (&game->texture[2]);
	}
	else
	{
		if (ray->dir_y > 0)
			return (&game->texture[1]);
		else
			return (&game->texture[0]);
	}
}
