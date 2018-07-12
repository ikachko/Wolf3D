/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:24:10 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:24:10 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	check_sound_and_x_hidden(t_game *game)
{
	if (game->pos_x >= 0 && game->pos_x < game->map_w
		&& game->pos_y >= 0 && game->pos_y < game->map_h
		&& (int)(game->pos_x) == 3 && (int)(game->pos_y) == 10)
	{
		system("killall afplay");
		system("afplay ./sound/boss_theme.mp3 &");
	}
	if (game->pos_x >= 0 && game->pos_x < game->map_w
		&& game->pos_y >= 0 && game->pos_y < game->map_h
		&& (int)(game->pos_x) == 3 && (int)(game->pos_y) == 18)
	{
		system("killall afplay");
		system("afplay ./sound/win_theme.mp3 &");
	}
	if ((int)(game->pos_x + game->dir_x * game->move_speed * 5 + 2)
		< game->map_h && (int)(game->pos_x + game->dir_x
			* game->move_speed * 5 - 2) >= 0
		&& game->world_map[(int)(game->pos_x + game->dir_x
		* game->move_speed * 5)][(int)game->pos_y] == 1)
	{
		game->world_map[(int)(game->pos_x + game->dir_x
		* game->move_speed * 5)][(int)game->pos_y] = 0;
	}
}

void		move_up(t_game *game)
{
	check_sound_and_x_hidden(game);
	if ((int)(game->pos_y + game->dir_y * game->move_speed * 5 + 2)
		< game->map_w && (int)(game->pos_y + game->dir_y
			* game->move_speed * 5 - 2) >= 0
		&& game->world_map[(int)game->pos_x][(int)(game->pos_y
		+ game->dir_y * game->move_speed * 5)] == 1)
	{
		game->world_map[(int)game->pos_x][(int)(game->pos_y
		+ game->dir_y * game->move_speed * 5)] = 0;
	}
	if ((int)(game->pos_x + game->dir_x * game->move_speed * 5) < game->map_h
		&& (int)(game->pos_x + game->dir_x * game->move_speed * 5) >= 0
		&& game->world_map[(int)(game->pos_x + game->dir_x
		* game->move_speed * 5)][(int)game->pos_y] == 0)
	{
		game->pos_x += game->dir_x * game->move_speed;
	}
	if ((int)(game->pos_y + game->dir_y * game->move_speed * 5) < game->map_w
		&& (int)(game->pos_y + game->dir_y * game->move_speed * 5) >= 0
		&& game->world_map[(int)game->pos_x][(int)(game->pos_y
		+ game->dir_y * game->move_speed * 5)] == 0)
	{
		game->pos_y += game->dir_y * game->move_speed;
	}
}

void		move_down(t_game *game)
{
	if (game->world_map[(int)(game->pos_x - game->dir_x
		* game->move_speed)][(int)(game->pos_y)] == 0)
		game->pos_x -= game->dir_x * game->move_speed;
	if (game->world_map[(int)(game->pos_x)][(int)(game->pos_y
		- game->dir_y * game->move_speed)] == 0)
		game->pos_y -= game->dir_y * game->move_speed;
}

void		move_left(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-(game->rot_speed))
	- game->dir_y * sin(-(game->rot_speed));
	game->dir_y = game->old_dir_x * sin(-(game->rot_speed))
	+ game->dir_y * cos(-(game->rot_speed));
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-(game->rot_speed))
	- game->plane_y * sin(-(game->rot_speed));
	game->plane_y = game->old_plane_x * sin(-(game->rot_speed))
	+ game->plane_y * cos(-(game->rot_speed));
}

void		move_right(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(game->rot_speed)
	- game->dir_y * sin(game->rot_speed);
	game->dir_y = game->old_dir_x * sin(game->rot_speed)
	+ game->dir_y * cos(game->rot_speed);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rot_speed)
	- game->plane_y * sin(game->rot_speed);
	game->plane_y = game->old_plane_x * sin(game->rot_speed)
	+ game->plane_y * cos(game->rot_speed);
}
