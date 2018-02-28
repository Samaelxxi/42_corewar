/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:32:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:32:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structs.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *link;

	if (lst)
	{
		first = f(lst);
		link = first;
		lst = lst->next;
		while (lst != NULL)
		{
			link->next = f(lst);
			link = link->next;
			lst = lst->next;
		}
	}
	else
		first = NULL;
	return (first);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	void	*content_mem;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(content_mem = ft_memalloc(content_size)))
		{
			free(link);
			return (NULL);
		}
		link->content = ft_memcpy(content_mem, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}

void	ft_lstremove(t_list **lst, t_list *elem, void del(void *, size_t))
{
	t_list *prev;
	t_list *cur;

	prev = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur == elem)
		{
			if (prev)
				prev->next = cur->next;
			else
				*lst = cur->next;
			ft_lstdelone(&cur, del);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	ft_lst_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while (*begin_list != NULL)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = (*begin_list);
		(*begin_list) = next;
	}
	(*begin_list) = prev;
}
