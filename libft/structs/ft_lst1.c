/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:31:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:31:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structs.h"

void	ft_lstadd(t_list **alst, t_list *new_elem)
{
	if (*alst == NULL)
		*alst = new_elem;
	else
	{
		new_elem->next = *alst;
		*alst = new_elem;
	}
}

void	ft_lstappend(t_list **alst, t_list *new_node)
{
	t_list *tmp;

	if (*alst == NULL)
		*alst = new_node;
	else
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*tmp;

	if (alst && *alst)
	{
		cur = *alst;
		tmp = cur->next;
		*alst = NULL;
		while (tmp != NULL)
		{
			ft_lstdelone(&cur, del);
			cur = tmp;
			tmp = cur->next;
		}
		ft_lstdelone(&cur, del);
	}
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	*alst = NULL;
}

int		ft_lstlen(t_list *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
