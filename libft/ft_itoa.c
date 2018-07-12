/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:14:45 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/02 16:14:46 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	j;
	int		len;

	len = ft_intdigitsize(n) - 1;
	i = 0;
	j = 1;
	if (!(s = ft_strnew(ft_intdigitsize(n))))
		return (NULL);
	if (n < 0)
	{
		*(s + i++) = '-';
		j = -1;
		len--;
	}
	while (len >= 0)
	{
		*(s + i++) = (n / ft_pow(10, len) * j) + '0';
		n %= ft_pow(10, len--);
	}
	*(s + i) = '\0';
	return (s);
}
