/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:59:06 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/03 14:59:07 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	if (!alst && !*alst && !del)
		alst = NULL;
	elem = *alst;
	if (elem->content)
	{
		while (elem)
		{
			del(elem->content, elem->content_size);
			free(elem);
			elem = elem->next;
		}
	}
	free(elem);
	*alst = NULL;
}
