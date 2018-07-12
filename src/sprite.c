/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:41:25 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:41:25 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	dist_swap(t_game *game)
{
	double	tmp;

	tmp = game->sprite_distance[game->i];
	game->sprite_distance[game->i] = game->sprite_distance[game->j];
	game->sprite_distance[game->j] = tmp;
}

static void	order_swap(t_game *game)
{
	int		tmp;

	tmp = game->sprite_order[game->i];
	game->sprite_order[game->i] = game->sprite_order[game->j];
	game->sprite_order[game->j] = tmp;
}

void		comb_sort(t_game *game)
{
	game->gap = NUMSPRITES;
	game->swapped = 0;
	while (game->gap > 1 || game->swapped)
	{
		game->gap = (game->gap * 10) / 13;
		if (game->gap == 9 || game->gap == 10)
			game->gap = 11;
		if (game->gap < 1)
			game->gap = 1;
		game->swapped = 0;
		game->i = -1;
		while (++(game->i) < NUMSPRITES - game->gap)
		{
			game->j = game->i + game->gap;
			if (game->sprite_distance[game->i]
				< game->sprite_distance[game->j])
			{
				dist_swap(game);
				order_swap(game);
				game->swapped = 1;
			}
		}
	}
}

void		sprite_calcs(t_game *game)
{
	game->sprite_height = abs(((int)(game->h / (game->transform_y))));
	game->draw_start_y = -(game->sprite_height) / 2 + game->h / 2;
	if (game->draw_start_y < 0)
		game->draw_start_y = 0;
	game->draw_end_y = game->sprite_height / 2 + game->h / 2;
	if (game->draw_end_y >= game->h)
		game->draw_end_y = game->h - 1;
	game->sprite_width = abs((int)(game->h / (game->transform_y)));
	game->draw_start_x = -(game->sprite_width) / 2 + game->sprite_screen_x;
	if (game->draw_start_x < 0)
		game->draw_start_x = 0;
	game->draw_end_x = game->sprite_width / 2 + game->sprite_screen_x;
	if (game->draw_end_x >= WIN_WIDTH)
		game->draw_end_x = WIN_WIDTH - 1;
}

void		make_sprite(t_game *game)
{
	game->i = -1;
	while (++(game->i) < NUMSPRITES)
	{
		game->sprite_x = game->sprite[game->sprite_order[game->i]].x
		- game->pos_x;
		game->sprite_y = game->sprite[game->sprite_order[game->i]].y
		- game->pos_y;
		game->inv_det = 1.0 / (game->plane_x * game->dir_y - game->dir_x
			* game->plane_y);
		game->transform_x = game->inv_det *
							(game->dir_y * game->sprite_x - game->dir_x
							* game->sprite_y);
		game->transform_y = game->inv_det *
							(-(game->plane_y) * game->sprite_x
								+ game->plane_x * game->sprite_y);
		game->sprite_screen_x = (int)((WIN_WIDTH / 2)
			* (1 + game->transform_x / game->transform_y));
		sprite_calcs(game);
		draw_sprite(game);
	}
}
