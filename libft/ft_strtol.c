/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:27:14 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/24 14:27:15 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	preparator(const char **str, int *neg, int base)
{
	*neg = 1;
	while (**str && ft_iswhitespace(**str))
		(*str)++;
	if (**str == '-')
	{
		*neg = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	if (base == 0 || base == 16)
	{
		if ((*str)[0] == '0' && (*str)[1] == 'x')
		{
			base = 16;
			(*str) += 2;
		}
	}
}

long		ft_strtol(const char *str, int base)
{
	int			c;
	int			neg;
	const char	*alphabet;
	long		val;
	const char	*idx;

	neg = 1;
	val = 0;
	alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base != 0 && (base < 2 || base > 36))
		return (0);
	preparator(&str, &neg, base);
	while ((c = *str))
	{
		idx = ft_memchr(alphabet, ft_tolower(c), base);
		if (idx == NULL)
			break ;
		val = val * base + (idx - alphabet);
		str++;
	}
	return (val * neg);
}

long		ft_strtolc(const char *str, int base, char end)
{
	int			c;
	int			neg;
	const char	*alphabet;
	long		val;
	const char	*idx;

	neg = 1;
	val = 0;
	alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base != 0 && (base < 2 || base > 36))
		return (0);
	preparator(&str, &neg, base);
	while ((c = *str) && c != end)
	{
		idx = ft_memchr(alphabet, ft_tolower(c), base);
		if (idx == NULL)
			break ;
		val = val * base + (idx - alphabet);
		str++;
	}
	return (val * neg);
}
