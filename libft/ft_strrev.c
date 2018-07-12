/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:32:56 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/02 17:32:56 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str) - 1;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (i < ft_strlen(str))
	{
		*(s + i) = *(str + len);
		len--;
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
