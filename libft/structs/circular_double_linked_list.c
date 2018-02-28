/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_double_linked_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:39:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/19 10:39:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cdll		*new_cdll_elem(void *data, size_t datasize)
{
	t_cdll	*new_elem;

	new_elem = malloc(sizeof(t_cdll));
	ft_memcpy(new_elem->data, data, datasize);
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	return (new_elem);
}

void		cdll_add(t_cdll **lst, t_cdll *elem)
{
	if (!lst)
		return ;
	else if (!(*lst))
		*lst = elem;
	else
	{
		elem->next = *lst;
		elem->prev = (*lst)->prev;
		(*lst)->prev->next = elem;
		(*lst)->prev = elem;
	}
}

void		cdll_append(t_cdll **lst, t_cdll *elem)
{
	if (!lst)
		return ;
	else if (!(*lst))
		*lst = elem;
	else
	{
		elem->next = *lst;
		elem->prev = (*lst)->prev;
		(*lst)->prev->next = elem;
		(*lst)->prev = elem;
	}
}

void		cdll_delete_elem(t_cdll **elem, void (*del)(t_cdll *elem))
{
	if (!elem || !(*elem))
		return ;
	else if ((*elem)->next == *elem)
	{
		del(*elem);
		free(*elem);
		*elem = NULL;
	}
	else
	{
		(*elem)->next->prev = (*elem)->prev;
		(*elem)->prev->next = (*elem)->next;
		del(*elem);
		free(*elem);
	}
}
