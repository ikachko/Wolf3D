/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:28:28 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/31 15:28:29 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*c;
	const char	*hay;

	hay = haystack;
	if (len == 0)
		return (NULL);
	if (!*needle || haystack == needle)
		return (char*)(haystack);
	while ((c = ft_strchr(haystack, needle[0])))
	{
		if ((unsigned)(c + ft_strlen(needle) - hay) > len)
			return (NULL);
		else if ((ft_strncmp(c, needle, (int)ft_strlen(needle)) == 0))
			return (c);
		haystack++;
	}
	return (NULL);
}
