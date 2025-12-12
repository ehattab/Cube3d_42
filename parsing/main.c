/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:50 by tony              #+#    #+#             */
/*   Updated: 2025/12/12 22:39:18 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	(void)av;
	(void)ac;
	// if (ac == 2)
	// {
	// 	check_file(av[1]);
	// }
	map.map = get_map1();
	search_position(map.map, &map);
	map.p = map.map[map.y][map.x];
	init_game(&game, &map);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
