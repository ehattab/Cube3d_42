/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:13 by ehattab           #+#    #+#             */
/*   Updated: 2025/12/13 21:13:53 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/cub3d.h"

// void	init_texture_img(t_game *game, t_img *image, char *path)
// {
// 	image->img = mlx_xpm_file_to_image(game->mlx, path,
// 	&image->width, &image->height);
// 	if (!image->img)
// 	{
// 		printf("Error\nTexture not found: %s\n", path);
// 		exit(1);
// 	}
// 	image->data = mlx_get_data_addr(image->img, &image->bpp,
// 	&image->size_line, &image->endian);
// }

// void	load_textures(t_game *game)
// {
// 	init_texture_img(game, &game->texture[0], "../src/yellow_wall.xpm");
// 	init_texture_img(game, &game->texture[1], "../src/green_wall.xpm");
// 	init_texture_img(game, &game->texture[2], "../src/red_wall.xpm");
// 	init_texture_img(game, &game->texture[3], "../src/blue_wall.xpm");
// }
