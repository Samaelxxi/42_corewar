/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structs.h"

t_list		*ft_lst_copy(t_list *lst)
{
	t_list *new_lst;

	new_lst = NULL;
	if (lst)
		while (lst)
		{
			ft_lstappend(&new_lst, ft_lstnew(lst->content, lst->content_size));
			lst = lst->next;
		}
	return (new_lst);
}

static void	remove_link(t_list *prev, t_list **link, t_list **first, void (*del)(void *, size_t))
{
	if (prev == NULL)
		*first = (*first)->next;
	else if ((*link)->next == NULL)
		prev->next = NULL;
	else
		prev->next = (*link)->next;
	del((*link)->content, (*link)->content_size);
	free(*link);
}

void		ft_list_remove_if(t_list **begin_list, int (*check)(t_list*), void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *begin_list;
	while (cur != NULL)
	{
		if (check(cur))
		{
			next = cur->next;
			remove_link(prev, &cur, begin_list, del);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void	swap_elems(t_list *cur, t_list *cur_next, t_list *prev, t_list **first)
{
	cur->next = cur_next->next;
	cur_next->next = cur;
	if (prev == NULL)
		*first = cur_next;
	else
		prev->next = cur_next;
}

void	ft_lst_sort(t_list **begin_list, int (*cmp)())
{
	int		is_sorted;
	t_list	*cur;
	t_list	*prev;

	if (!(*begin_list))
		return ;
	is_sorted = 0;
	while (!is_sorted)
	{
		prev = NULL;
		is_sorted = 1;
		cur = *begin_list;
		while (cur->next != NULL)
		{
			if (cmp(cur->content, cur->next->content) > 0)
			{
				swap_elems(cur, cur->next, prev, begin_list);
				is_sorted = 0;
			}
			prev = cur;
			if (cur->next != NULL)
				cur = cur->next;
		}
	}
}
