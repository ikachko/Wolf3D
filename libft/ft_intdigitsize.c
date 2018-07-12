/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdigitsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:20:51 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/02 16:20:52 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intdigitsize(int num)
{
	size_t		i;
	long int	nb;

	nb = num;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb == -0)
		return (2);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
