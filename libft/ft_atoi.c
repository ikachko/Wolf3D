/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:21:23 by ikachko           #+#    #+#             */
/*   Updated: 2018/03/20 16:21:23 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	result;
	int				minus;
	int				i;

	i = 0;
	minus = 1;
	result = 0;
	while (ft_iswhitespace(*(str + i)))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			minus = -1;
		i++;
	}
	while (ft_isdigit(*(str + i)))
	{
		result += *(str + i) - '0';
		if (ft_isdigit(*(str + i + 1)))
			result *= 10;
		i++;
	}
	return (minus * result);
}
