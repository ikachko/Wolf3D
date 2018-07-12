/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:44:18 by ikachko           #+#    #+#             */
/*   Updated: 2018/05/27 20:44:19 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	exit_x(void *par)
{
	par = NULL;
	system("killall afplay");
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if ((game = (t_game*)ft_memalloc(sizeof(t_game))))
		game_init(game);
	init_textures(game);
	game->quit = 0;
	if (ac == 2)
	{
		if (!(file_open(game, av[1])))
			str_error("Wrong file!");
		game->filename = ft_strdup(av[1]);
		if (ft_strequ(game->filename, "maps/default"))
			init_sprites(game);
	}
	else
		str_error("Usage: ./wolf3d [mapName]");
	init_game(game);
	wolf_threads(game);
	mlx_do_key_autorepeatoff(game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, hook_loop, game);
	mlx_hook(game->win_ptr, KEYPRESS, KEYPRESSMASK, press_key, game);
	mlx_hook(game->win_ptr, 17, KEYPRESSMASK, exit_x, game);
	mlx_key_hook(game->win_ptr, hook_key, game);
	mlx_loop(game->mlx_ptr);
}
