/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:30:10 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/31 15:30:11 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;
	unsigned const char		*str1;
	unsigned const char		*str2;

	i = 0;
	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	if (!*str1 || !*str2)
		return (*str1 - *str2);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((*(str1 + i) - *(str2 + i)));
	}
	return (0);
}
