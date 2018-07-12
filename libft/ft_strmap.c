/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:28:19 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/02 14:28:20 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *res;

	if (!s || !f)
		return (NULL);
	if (!(str = ft_strnew(((int)ft_strlen(s)))))
		return (NULL);
	res = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (res);
}
