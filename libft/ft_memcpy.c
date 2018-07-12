/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:28:17 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/21 15:57:05 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	if (!dst && !src)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
