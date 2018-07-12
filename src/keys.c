/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:22:32 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:22:32 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		hook_loop(t_game *game)
{
	char	*fps;

	game->old_time = game->time;
	game->time = clock();
	game->frame_time = (game->time - game->old_time) / 1000.0;
	fps = ft_itoa((int)(1000 / game->frame_time));
	if (game->move_up)
		move_up(game);
	if (game->move_down)
		move_down(game);
	if (game->move_left)
		move_right(game);
	if (game->move_right)
		move_left(game);
	clear_image(game);
	wolf_threads(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 60, 60, 0xFFFFFF, fps);
	free(fps);
	return (0);
}

void	move_key(int key, t_game *game)
{
	if (key == UP)
		game->move_up = !game->move_up;
	if (key == DOWN)
		game->move_down = !game->move_down;
	if (key == LEFT)
		game->move_left = !game->move_left;
	if (key == RIGHT)
		game->move_right = !game->move_right;
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		system("killall afplay");
		exit(0);
	}
}

int		hook_key(int key, t_game *game)
{
	move_key(key, game);
	return (0);
}

int		press_key(int key, t_game *game)
{
	move_key(key, game);
	return (0);
}
