/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:29:48 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/22 14:29:48 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_from_fd_line(char **remain, char **line)
{
	char	*to_find;

	to_find = ft_strchr(*remain, '\n');
	if (!to_find)
		return (0);
	else
	{
		*line = ft_strsub(*remain, 0, to_find - *remain);
		ft_memmove(*remain, to_find + 1, ft_strlen(to_find));
		to_find = NULL;
		return (1);
	}
}

static int	read_from_file(const int fd, char **fd_line, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = NULL;
		if (!*fd_line)
			*fd_line = ft_strdup(buf);
		else
		{
			temp = ft_strdup(*fd_line);
			ft_strdel(fd_line);
			*fd_line = ft_strjoin(temp, buf);
			ft_strdel(&temp);
		}
		if (get_from_fd_line(fd_line, line) == 1)
			return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fd_lines[8192];
	int			read;

	if (!line || fd < 0 || fd > 256)
		return (-1);
	if (fd_lines[fd] && get_from_fd_line(&fd_lines[fd], line))
		return (1);
	else
		read = read_from_file(fd, &fd_lines[fd], line);
	if (read != 0)
		return (read);
	if (!fd_lines[fd] || !*fd_lines[fd])
		return (0);
	*line = ft_strdup(fd_lines[fd]);
	ft_strclr(fd_lines[fd]);
	return (1);
}
