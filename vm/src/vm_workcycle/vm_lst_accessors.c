/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct_getters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:54:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 11:54:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_structs.h"

t_arg			*lst_get_arg(t_list *lst)
{
	return (*((t_arg**)(lst->content)));
}

void			lst_add_arg(t_list **lst, t_arg *arg)
{
	ft_lstadd(lst, ft_lstnew(&arg, sizeof(t_arg*)));
}

t_player		*lst_get_player(t_list *lst)
{
	return (*((t_player**)(lst->content)));
}

void			lst_add_player(t_list **lst, t_player *player)
{
	ft_lstappend(lst, ft_lstnew(&player, sizeof(t_player*)));
}

t_bytes_to_write	*lst_get_write_bytes(t_list *lst)
{
	return (*((t_bytes_to_write**)(lst->content)));
}

void			lst_add_write_bytes(t_list **lst, t_bytes_to_write *bytes)
{
	ft_lstadd(lst, ft_lstnew(&bytes, sizeof(t_bytes_to_write*)));
}

t_process		*lst_get_process(t_list *lst)
{
	return (*((t_process**)(lst->content)));
}

void			lst_add_process(t_list **lst, t_process *process)
{
	ft_lstadd(lst, ft_lstnew(&process, sizeof(t_process*)));
}

void			lst_append_process(t_list **lst, t_process *process)
{
	ft_lstadd(lst, ft_lstnew(&process, sizeof(t_process*)));
}
