/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:34:20 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:34:20 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	floor_casting(t_game *game)
{
	if (game->side == 0 && game->ray_dir_x > 0)
	{
		game->floor_x_wall = game->map_x;
		game->floor_y_wall = game->map_y + game->wall_x;
	}
	else if (game->side == 0 && game->ray_dir_x < 0)
	{
		game->floor_x_wall = game->map_x + 1.0;
		game->floor_y_wall = game->map_y + game->wall_x;
	}
	else if (game->side == 1 && game->ray_dir_y > 0)
	{
		game->floor_x_wall = game->map_x + game->wall_x;
		game->floor_y_wall = game->map_y;
	}
	else
	{
		game->floor_x_wall = game->map_x + game->wall_x;
		game->floor_y_wall = game->map_y + 1.0;
	}
	game->dist_wall = game->perp_wall_dist;
	game->dist_player = 0.0;
	if (game->draw_end < 0)
		game->draw_end = game->h;
}

static void	ray_caster(t_game *game)
{
	while (++(game->x) <= game->x_max)
	{
		text_calcs(game);
		wall_draw(game);
		floor_casting(game);
		floor_drawing(game);
	}
	game->i = -1;
	while (++(game->i) < NUMSPRITES)
	{
		game->sprite_order[game->i] = game->i;
		game->sprite_distance[game->i] =
		((game->pos_x - game->sprite[game->i].x)
		* (game->pos_x - game->sprite[game->i].x)
		+ (game->pos_y - game->sprite[game->i].y)
		* (game->pos_y - game->sprite[game->i].y));
	}
	comb_sort(game);
	make_sprite(game);
}

static void	*rc(void *game)
{
	t_game *g;

	g = (t_game*)game;
	ray_caster(g);
	return (game);
}

void		wolf_threads(t_game *game)
{
	t_game		tab[20];
	pthread_t	t[20];
	int			i;

	i = -1;
	while (++i < 20)
	{
		ft_memcpy((void*)&tab[i], (void*)game, sizeof(t_game));
		tab[i].x = 32 * i;
		tab[i].x_max = 32 * (i + 1);
	}
	i = 0;
	while (++i <= 20)
		pthread_create(&t[i - 1], NULL, rc, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
}
