/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:46:02 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 18:46:02 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init_textures_3(t_game *game)
{
	void	*temp_xpm;

	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/wood.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/wood.xpm>");
	if (!(game->textures[6] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/colorstone.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/colorstone.xpm>");
	if (!(game->textures[7] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/barrel.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/barrel.xpm>");
	if (!(game->textures[8] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
}

static void		init_textures_2(t_game *game)
{
	void	*temp_xpm;

	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/eagle.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/eagle.xpm>");
	if (!(game->textures[0] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/redbrick.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/redbrick.xpm>");
	if (!(game->textures[1] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/purplestone.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/purplestone.xpm>");
	if (!(game->textures[2] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
}

static void		init_textures_1(t_game *game)
{
	void	*temp_xpm;

	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/greystone.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/greystone.xpm>");
	if (!(game->textures[3] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/bluestone.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/bluestone.xpm>");
	if (!(game->textures[4] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/mossy.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/mossy.xpm>");
	if (!(game->textures[5] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
}

static void		init_textures_4(t_game *game)
{
	void	*temp_xpm;

	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/pillar.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/pillar.xpm>");
	if (!(game->textures[9] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/greenlight.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/greenlight.xpm>");
	if (!(game->textures[10] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
	if (!(temp_xpm = mlx_xpm_file_to_image(game->mlx_ptr,
		"./textures/gitl_r.xpm", &game->tex_w, &game->tex_h)))
		str_error("Error on texture initialization!\
			<./textures/gitl_r.xpm>");
	if (!(game->textures[11] = (int*)mlx_get_data_addr(temp_xpm,
		&game->bpp, &game->size_line, &game->endian)))
		str_error("Error on getting mlx data addr!");
}

void			init_textures(t_game *game)
{
	init_textures_1(game);
	init_textures_2(game);
	init_textures_3(game);
	init_textures_4(game);
}
