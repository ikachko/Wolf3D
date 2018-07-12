/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:01:51 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/03 13:01:51 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	count_word(char const *s, char c, size_t i)
{
	size_t	word;

	word = 0;
	while (*(s + i) != c && *(s + i) != '\0')
	{
		word++;
		i++;
	}
	return (word);
}

static size_t	skip_char(const char *s, char c, size_t i)
{
	while (*(s + i) == c && *(s + i) != '\0')
		i++;
	return (i);
}

static size_t	skip_word(const char *s, char c, size_t i)
{
	while (*(s + i) != c && *(s + i) != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	if (!s)
		return (NULL);
	if ((!(result = (char**)malloc(sizeof(char*) * \
										ft_count_words(s, c) + 1))))
		return (NULL);
	while (*(s + i) != '\0' && words < ft_count_words(s, c))
	{
		i = skip_char(s, c, i);
		if (*(s + i) != '\0')
			*(result + words) = ft_strsub(s, i, count_word(s, c, i));
		i = skip_word(s, c, i);
		words++;
	}
	*(result + ft_count_words(s, c)) = NULL;
	return (result);
}
