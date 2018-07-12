/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:43:21 by ikachko           #+#    #+#             */
/*   Updated: 2018/06/07 17:43:21 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_sprite	new_sprite(double x, double y, int texture)
{
	t_sprite	s;

	s.x = x;
	s.y = y;
	s.texture = texture;
	return (s);
}

void		clear_str2(char ***str)
{
	int j;

	j = 0;
	while ((*str)[j] != NULL)
	{
		ft_strdel(&(*str)[j]);
		j++;
	}
	free((*str));
	str = NULL;
}

void		map_error(char ***str)
{
	if (str)
		clear_str2(str);
	ft_putendl("Error map!");
	exit(1);
}

void		str_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
