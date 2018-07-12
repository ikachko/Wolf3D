/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:24:40 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/04 16:24:41 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *lst)
{
	int		size;
	t_list	*node;

	size = 0;
	if (lst)
	{
		node = lst;
		while (node)
		{
			size++;
			node = node->next;
		}
	}
	return (size);
}
