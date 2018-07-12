/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:38:49 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:38:50 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	calc_step(t_game *game)
{
	game->hit = 0;
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x)
		* game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x)
		* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y)
		* game->delta_dist_y;
	}
}

static void	dda(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->world_map[game->map_x][game->map_y] > 0)
			game->hit = 1;
	}
}

void		prep_calcs(t_game *game)
{
	game->camera_x = (2 * game->x) / (double)(WIN_WIDTH) - 1;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)(game->pos_x);
	game->map_y = (int)(game->pos_y);
	game->delta_dist_x = fabs(1 / game->ray_dir_x);
	game->delta_dist_y = fabs(1 / game->ray_dir_y);
	calc_step(game);
	dda(game);
	if (game->side == 0)
		game->perp_wall_dist = ((double)game->map_x - game->pos_x +
			(1.0 - (double)game->step_x) / 2.0) / game->ray_dir_x;
	else
		game->perp_wall_dist = ((double)game->map_y - game->pos_y +
			(1.0 - (double)game->step_y) / 2.0) / game->ray_dir_y;
	game->line_height = (int)((double)game->h / game->perp_wall_dist);
	game->draw_start = -(game->line_height) / 2 + game->h / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->h / 2;
	if (game->draw_end >= game->h)
		game->draw_end = game->h - 1;
}

void		text_calcs(t_game *game)
{
	prep_calcs(game);
	game->tex_num = game->world_map[game->map_x][game->map_y] - 1;
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x -= floor((game->wall_x));
	game->tex_x = (int)(game->wall_x * (double)(TEXWIDTH));
	if (game->side == 0 && game->ray_dir_x > 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	if (game->side == 1 && game->ray_dir_y < 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
}
