/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:24:24 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/03 16:24:24 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *elem)
{
	t_list	*list;

	list = *alst;
	if (elem)
	{
		while ((*alst)->next)
		{
			(*alst) = (*alst)->next;
		}
		(*alst)->next = elem;
		(*alst) = list;
	}
}
