/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:36:30 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:36:30 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_pxl_to_img(t_game *game, int x, int y, int color)
{
	if (x < WIN_WIDTH && y < WIN_WIDTH)
	{
		color = mlx_get_color_value(game->mlx_ptr, color);
		ft_memcpy(game->img + 4 * WIN_WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void		clear_image(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			put_pxl_to_img(game, j, i, 0x000000);
	}
}

void		floor_drawing(t_game *game)
{
	game->y = game->draw_end;
	while (++(game->y) < game->h)
	{
		game->current_dist = game->h / (2.0 * game->y - game->h);
		game->weight = (game->current_dist - game->dist_player)
		/ (game->dist_wall - game->dist_player);
		game->current_floor_x = game->weight * game->floor_x_wall
		+ (1.0 - game->weight) * game->pos_x;
		game->current_floor_y = game->weight * game->floor_y_wall
		+ (1.0 - game->weight) * game->pos_y;
		game->floor_tex_x = (int)(game->current_floor_x * TEXWIDTH) % TEXWIDTH;
		game->floor_tex_y = (int)(game->current_floor_y * TEXHEIGHT)
		% TEXHEIGHT;
		game->color = (game->textures[3][TEXWIDTH *
			game->floor_tex_y + game->floor_tex_x] >> 1) & 8355711;
		put_pxl_to_img(game, game->x, game->y, game->color);
		game->color = game->textures[6]
		[TEXWIDTH * game->floor_tex_y + game->floor_tex_x];
		put_pxl_to_img(game, game->x, game->h - game->y, game->color);
	}
}

static void	get_tex_x(t_game *game)
{
	game->tex_x = (int)(256 * (game->stripe -
		(-(game->sprite_width) / 2 + game->sprite_screen_x))
		* TEXWIDTH / game->sprite_width / 256);
}

void		draw_sprite(t_game *game)
{
	game->stripe = game->draw_start_x - 1;
	while (++(game->stripe) < game->draw_end_x)
	{
		get_tex_x(game);
		if (game->transform_y > 0 && game->stripe > 0
			&& game->stripe < WIN_WIDTH
			&& game->transform_y < game->z_buffer[game->stripe])
		{
			game->y = game->draw_start_y - 1;
			while (++(game->y) < game->draw_end_y)
			{
				game->d = (game->y) * 256 - game->h * 128
				+ game->sprite_height * 128;
				game->tex_y = ((game->d * TEXHEIGHT)
					/ game->sprite_height) / 256;
				game->color = game->textures
				[game->sprite[game->sprite_order[game->i]].texture]
				[TEXWIDTH * game->tex_y + game->tex_x];
				if ((game->color & 0x00FFFFFF) != 0)
					put_pxl_to_img(game,
						game->stripe, game->y, game->color);
			}
		}
	}
}
