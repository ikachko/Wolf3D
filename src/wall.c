/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:32:25 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:32:25 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	shit_wall(t_game *game)
{
	if (game->side && game->ray_dir_y > 0)
		game->color = game->textures[1][game->tex_w
												* game->tex_y + game->tex_x];
	else if (game->side && game->ray_dir_y < 0)
		game->color = game->textures[2][game->tex_w
												* game->tex_y + game->tex_x];
	else if (game->ray_dir_x > 0)
		game->color = game->textures[3][game->tex_w
												* game->tex_y + game->tex_x];
	else
		game->color = game->textures[4][game->tex_w
												* game->tex_y + game->tex_x];
}

void		wall_draw(t_game *game)
{
	game->y = game->draw_start - 1;
	while (++(game->y) < game->draw_end)
	{
		game->d = game->y * 512 - game->h * 256 + game->line_height * 256;
		game->tex_y = ((game->d * TEXHEIGHT) / game->line_height) / 512;
		if (ft_strequ(game->filename, "maps/test_map"))
			shit_wall(game);
		else
			game->color = game->textures[game->tex_num]
		[game->tex_w * game->tex_y + game->tex_x];
		if (game->side == 1)
			game->color = (game->color >> 1) & 8355711;
		put_pxl_to_img(game, game->x, game->y, game->color);
	}
	game->z_buffer[game->x] = game->perp_wall_dist;
}
