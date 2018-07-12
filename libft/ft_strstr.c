/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:58:53 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/31 19:58:53 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*c;

	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return (char*)(haystack);
	while ((c = ft_strchr(haystack, needle[0])))
	{
		if ((i = ft_strncmp(c, needle, ft_strlen(needle)) == 0))
			return (c);
		haystack++;
	}
	return (NULL);
}
