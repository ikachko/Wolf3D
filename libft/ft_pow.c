/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:58:16 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/01 15:58:27 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int num, int power)
{
	int i;
	int b;

	b = num;
	i = 0;
	if (num == 0)
		return (0);
	else if (num == 1 || power == 0)
		return (1);
	else if (power == 1)
		return (num);
	else
	{
		if (power > 0)
			while (--power != 0)
				num *= b;
		else if (power < 0)
			num = 1 / ft_pow(num, power);
	}
	return (num);
}
