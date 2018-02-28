/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_search_same_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 11:18:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/18 11:18:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int 			search_same_label(char *name_label, t_list *point_line)
{
	t_list	*token_pointer;

	while (point_line)
	{
		token_pointer = lst_get_line_token(point_line)->tokens;
		if (search_in_line(token_pointer, name_label))
			return (1);
		point_line = point_line->next;
	}
	return (0);
}

int 			search_in_line(t_list *token_pointer, char *name_label)
{
	t_token *token;

	while(token_pointer)
	{
		token = lst_get_token(token_pointer);
		if (token->token_type == TOKEN_LABEL)
			if (compare_name_labels(name_label, token->token_string))
				return (1);
		token_pointer = token_pointer->next;
	}
	return (0);
}

int 			compare_name_labels(char *name_label, char *label_string)
{
	if (ft_strlen(name_label) + 1 == ft_strlen(label_string))
		if (!ft_strncmp(name_label, label_string, ft_strlen(name_label)))
			return (1);
	return(0);
}


