/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikachko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:41:59 by ikachko           #+#    #+#             */
/*   Updated: 2018/04/03 14:42:00 by ikachko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
	{
		free(elem);
		return (NULL);
	}
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = malloc(content_size)))
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy((elem->content), content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
