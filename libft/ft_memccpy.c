/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:27:07 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/31 11:27:08 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (!n && !dst && !src)
		return (NULL);
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		if (*(d + i++) == (unsigned char)c)
			return (d + i);
	}
	return (NULL);
}
