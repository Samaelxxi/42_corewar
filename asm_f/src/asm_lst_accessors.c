/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lst_accessors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:05:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 12:05:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_structs.h"

t_line_of_tokens		*lst_get_line_token(t_list *lst)
{
	return (*((t_line_of_tokens**)(lst->content)));
}

void					lst_add_line_token(t_list **lst, t_line_of_tokens *line_lexem)
{
	ft_lstadd(lst, ft_lstnew(&line_lexem, sizeof(t_line_of_tokens*)));
}

t_token					*lst_get_token(t_list *lst)
{
	return (*((t_token**)(lst->content)));
}

void					lst_add_token(t_list **lst, t_token *lexem)
{
	ft_lstadd(lst, ft_lstnew(&lexem, sizeof(t_token*)));
}

t_parsed_command		*lst_get_command(t_list *lst)
{
	return (*((t_parsed_command**)(lst->content)));
}

void					lst_add_command(t_list **lst, t_parsed_command *command)
{
	ft_lstadd(lst, ft_lstnew(&command, sizeof(t_parsed_command*)));
}

t_page_dict_label		*lst_get_page_dict_lable(t_list *lst)
{
	return (*((t_page_dict_label**)(lst->content)));
}

void					lst_add_page_dict_lable(t_list **lst, t_page_dict_label *page_dict_label)
{
	ft_lstadd(lst, ft_lstnew(&page_dict_label, sizeof(t_page_dict_label*)));
}