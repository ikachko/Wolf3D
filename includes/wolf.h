/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:34:33 by ikachko           #+#    #+#             */
/*   Updated: 2018/05/27 17:34:33 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>

# define WIN_WIDTH 640
# define BPP 32
# define WIN_NAME "WOLF3D"
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define NUMOFTEXTS 12
# define NUMSPRITES 30
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define ESC 53
# define KEYPRESS	2
# define KEYPRESSMASK (1L<<0)

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_ptr;
	int			**world_map;
	int			*textures[NUMOFTEXTS];
	t_sprite	sprite[NUMSPRITES];
	double		z_buffer[WIN_WIDTH];
	int			sprite_order[NUMSPRITES];
	double		sprite_distance[NUMSPRITES];
	char		*filename;
	int			bpp;
	double		camera_x;
	int			color;
	double		current_dist;
	double		current_floor_x;
	double		current_floor_y;
	int			d;
	double		delta_dist_x;
	double		delta_dist_y;
	double		dir_x;
	double		dir_y;
	double		dist_wall;
	double		dist_player;
	int			draw_start;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end;
	int			draw_end_x;
	int			draw_end_y;
	int			endian;
	int			fd;
	double		floor_x_wall;
	double		floor_y_wall;
	int			floor_tex_x;
	int			floor_tex_y;
	double		frame_time;
	int			gap;
	int			h;
	int			hit;
	int			i;
	double		inv_det;
	int			j;
	int			line_height;
	int			map_x;
	int			map_y;
	int			map_w;
	int			map_h;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	double		move_speed;
	double		old_dir_x;
	double		old_plane_x;
	double		old_time;
	double		perp_wall_dist;
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		rot_speed;
	double		side_dist_x;
	double		side_dist_y;
	int			size_line;
	int			step_x;
	int			step_y;
	int			side;
	double		sprite_x;
	double		sprite_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			stripe;
	int			swapped;
	int			tex_num;
	int			tex_w;
	int			tex_h;
	int			tex_x;
	int			tex_y;
	double		time;
	double		transform_x;
	double		transform_y;
	double		wall_x;
	double		weight;
	int			x;
	int			x_max;
	int			y;
	int			quit;
}				t_game;

void			clear_image(t_game *game);
void			clear_str2(char ***str);
void			comb_sort(t_game *game);
void			draw_sprite(t_game *game);
int				file_open(t_game *game, char *filename);
void			floor_drawing(t_game *game);
void			game_init(t_game *game);
int				hook_key(int key, t_game *game);
int				hook_loop(t_game *game);
void			init_game(t_game *game);
void			init_textures(t_game *game);
void			init_sprites(t_game *game);
void			make_sprite(t_game *game);
void			map_error(char ***str);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			move_up(t_game *game);
void			move_key(int key, t_game *game);
t_sprite		new_sprite(double x, double y, int texture);
void			prep_calcs(t_game *game);
int				press_key(int key, t_game *game);
void			put_pxl_to_img(t_game *game, int x, int y, int color);
void			sprite_calcs(t_game *game);
void			str_error(char *str);
void			text_calcs(t_game *game);
void			wall_draw(t_game *game);
void			wolf_threads(t_game *game);
#endif
