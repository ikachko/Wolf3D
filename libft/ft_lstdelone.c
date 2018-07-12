/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:53:33 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/03 14:53:35 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	if (!alst || !*alst || !del)
		alst = NULL;
	elem = *alst;
	if (elem->content)
		del(elem->content, elem->content_size);
	free(elem);
	*alst = NULL;
}
