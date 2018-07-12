/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:13:37 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:13:37 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			game_init(t_game *game)
{
	if (!(game->mlx_ptr = mlx_init()))
	{
		ft_putendl("Error on MLX Initiation!");
		exit(1);
	}
	if (!(game->win_ptr = mlx_new_window(game->mlx_ptr,
		WIN_WIDTH, WIN_WIDTH, WIN_NAME)))
	{
		ft_putendl("Error on window opening!");
		exit(1);
	}
	if (!(game->img_ptr = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_WIDTH)))
	{
		ft_putendl("Error on image initiation!");
		exit(1);
	}
	game->size_line = WIN_WIDTH;
	game->bpp = 4;
	game->endian = 2;
	if (!(game->img = mlx_get_data_addr(game->img_ptr,
		&game->bpp, &game->size_line, &game->endian)))
	{
		ft_putendl("Error on img addr creation!");
		exit(1);
	}
}

void			init_game(t_game *game)
{
	game->tex_w = 64;
	game->tex_h = 64;
	game->h = 640;
	game->dir_x = -1.0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->time = 0;
	game->old_time = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
	game->rot_speed = 0.05;
	game->move_speed = 0.05;
	system("afplay ./sound/main_theme.mp3 &");
}

static void		init_sprites_15(t_game *game)
{
	game->sprite[0] = new_sprite(20.5, 11.5, 10);
	game->sprite[1] = new_sprite(18.5, 4.5, 10);
	game->sprite[2] = new_sprite(10.0, 4.5, 10);
	game->sprite[3] = new_sprite(10.0, 12.5, 10);
	game->sprite[4] = new_sprite(3.5, 6.5, 10);
	game->sprite[5] = new_sprite(3.5, 20.5, 10);
	game->sprite[6] = new_sprite(2.5, 14.5, 10);
	game->sprite[7] = new_sprite(14.5, 20.5, 10);
	game->sprite[8] = new_sprite(18.5, 10.5, 9);
	game->sprite[9] = new_sprite(18.5, 11.5, 9);
	game->sprite[10] = new_sprite(18.5, 12.5, 9);
	game->sprite[11] = new_sprite(21.5, 1.5, 8);
	game->sprite[12] = new_sprite(15.5, 1.5, 8);
	game->sprite[13] = new_sprite(16.0, 1.8, 8);
	game->sprite[14] = new_sprite(16.2, 1.2, 8);
	game->sprite[15] = new_sprite(3.5, 14.5, 11);
}

void			init_sprites(t_game *game)
{
	init_sprites_15(game);
	game->sprite[16] = new_sprite(9.5, 15.5, 8);
	game->sprite[17] = new_sprite(10.0, 15.1, 8);
	game->sprite[18] = new_sprite(10.5, 15.8, 8);
	game->sprite[19] = new_sprite(1.5, 12.5, 9);
	game->sprite[20] = new_sprite(1.5, 13.5, 9);
	game->sprite[21] = new_sprite(1.5, 14.5, 9);
	game->sprite[22] = new_sprite(1.5, 15.5, 9);
	game->sprite[23] = new_sprite(1.5, 16.5, 9);
	game->sprite[24] = new_sprite(5.5, 12.5, 9);
	game->sprite[25] = new_sprite(5.5, 13.5, 9);
	game->sprite[26] = new_sprite(5.5, 14.5, 9);
	game->sprite[27] = new_sprite(5.5, 15.5, 9);
	game->sprite[28] = new_sprite(5.5, 16.5, 9);
	game->sprite[29] = new_sprite(4.5, 14.5, 10);
}
