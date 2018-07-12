/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:15:01 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:15:02 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		check_pos(t_game *game)
{
	if (game->map_w < 0 || game->map_h < 0 || game->pos_x < 0 ||
			game->pos_y < 0 || game->pos_x >= game->map_w ||
			game->pos_y >= game->map_w)
		map_error(NULL);
}

static void		read_pos(int fd, t_game *game)
{
	char	*line;
	char	**str;
	int		i;

	i = -1;
	line = NULL;
	str = NULL;
	if (get_next_line(fd, &line) < 1)
	{
		free(line);
		map_error(NULL);
	}
	str = ft_strsplit(line, ' ');
	ft_strdel(&line);
	while (str[++i] != '\0')
		;
	if (i != 4)
		map_error(&str);
	game->map_w = ft_atoi(str[0]);
	game->map_h = ft_atoi(str[1]);
	game->pos_x = ft_atoi(str[2]) + 0.5;
	game->pos_y = ft_atoi(str[3]) + 0.5;
	clear_str2(&str);
	check_pos(game);
}

static void		read_line(char *line, int y, int **map, t_game *game)
{
	int		x;
	char	**str;

	x = -1;
	if (y >= game->map_h)
		map_error(NULL);
	str = ft_strsplit(line, ' ');
	map[y] = (int *)malloc(sizeof(int *) * WIN_WIDTH);
	while (str[++x] != '\0')
	{
		if (!(str[x][0] >= '0' && str[x][0] <= '9'
				&& ft_atoi(str[x]) >= 0
				&& ft_atoi(str[x]) <= NUMOFTEXTS && x < game->map_w))
			map_error(&str);
		map[y][x] = ft_atoi(str[x]);
		if ((x == 0 || x == game->map_w - 1 || y == 0 || y == game->map_h -
													1) && map[y][x] == 0)
			map_error(&str);
	}
	if (x != game->map_w)
		map_error(&str);
	clear_str2(&str);
}

static int		read_file(int fd, t_game *game)
{
	char	*line;
	int		y;
	int		**map;

	y = -1;
	read_pos(fd, game);
	map = (int **)malloc(sizeof(int **) * game->map_h);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, ++y, map, game);
		ft_strdel(&line);
	}
	if (map[(int)game->pos_x][(int)game->pos_y] != 0)
		map_error(NULL);
	game->world_map = map;
	return (1);
}

int				file_open(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (read_file(fd, game));
}
