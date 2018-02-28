/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_inst_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:03:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/21 20:03:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

u_int8_t 		extract_coding_byte(t_list *line)
{
	if (present_coding_byte(lst_get_token(line)))
		return(form_coding_byte(line->next));
	return (0);
}

int 			present_coding_byte(t_token *token)
{
	int	i;

	i = 1;
	while (i < (NUM_OF_INST + 1))
	{
		if (ft_strequ(token->token_string, g_op_tab[i].name))
			return(g_op_tab[i].is_encoding_byte);
		i++;
	}
	return (0);
}

uint8_t			form_coding_byte(t_list *token)
{
	int 	shift;
	int 	coding_byte;
	int		type_value;

	shift = 6;
	coding_byte = 0;
	while (token)
	{
		type_value = lst_get_token(token)->token_type;
		if (type_value != TOKEN_SEPARATOR)
		{
			if (type_value == T_IND)
				type_value = T_IND - 1;
			coding_byte |= (type_value << shift);
			shift = shift - 2;
		}
		token = token->next;
	}
	return ((uint8_t)coding_byte);
}

void			fill_arg_strs(t_list *line, t_parsed_command *command)
{
	t_list		*tmp_token;
	char		**arg_strs_copy;

	arg_strs_copy = command->arg_strs;
	tmp_token = line->next;
	while (tmp_token)
	{
		if (lst_get_token(tmp_token)->token_type != TOKEN_SEPARATOR)
		{
			*arg_strs_copy = lst_get_token(tmp_token)->token_string;
			arg_strs_copy++;
		}
		tmp_token = tmp_token->next;
	}
}
