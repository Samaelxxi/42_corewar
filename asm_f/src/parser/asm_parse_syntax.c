/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_syntax_error(t_line_of_tokens *line_of_tokens)
{
	t_token		*token;
	t_list		*token_list;

	if (line_of_tokens)
		if ((token_list = line_of_tokens->tokens))
		{
			token = lst_get_token(token_list);
			if (token && check_label(token, token_list, line_of_tokens))
				return (1);
		}
	return (0);
}

int		check_label(t_token *token, t_list *token_list, t_line_of_tokens *line)
{
	t_list *token_line;

	if (token->token_type == TOKEN_LABEL)
	{
		if ((token_line = token_list->next))
			if ((token = lst_get_token(token_line)))
				if (!check_instruction(token, token_line, line))
					return (0);
		return (1);
	}
	else if (token->token_type == TOKEN_INSTR)
	{
		if (check_instruction(token, token_list, line))
			return (1);
		return (0);
	}
	syntax_error(line->line_number, token->start_lexem_position,
							line->origin_line, INV_FISRT_TOKEN);
	return (0);
}

int		check_instruction(t_token *token, t_list *token_list,
										t_line_of_tokens *line)
{
	int		opcode;
	int		err_position;

	opcode = get_opcode_instr(token->token_string);
	if ((token_list = token_list->next))
		if ((token = lst_get_token(token_list)))
		{
			if (check_arguments(token, token_list, line, opcode))
				return (1);
			return (0);
		}
	err_position = token->start_lexem_position +
				(int)ft_strlen(token->token_string);
	syntax_error(line->line_number, err_position, line->origin_line, NO_ARGS);
	return (0);
}

int		check_arguments(t_token *token, t_list *token_list,
							t_line_of_tokens *line, int opcode)
{
	if (check_argument_cicle(token, &token_list, line, opcode) == 0)
		return (0);
	if (!token_list)
		return (1);
	syntax_error(line->line_number, token->start_lexem_position,
								line->origin_line, EXTRA_ARGS_ERR);
	return (0);
}

int		check_argument_cicle(t_token *token, t_list **token_list,
									t_line_of_tokens *line, int opcode)
{
	int		index_type_args;
	int		nbr_args;

	index_type_args = 0;
	nbr_args = g_op_tab[opcode].arg_num;
	change_value_token_type(token);
	while (index_type_args < nbr_args)
	{
		if (index_type_args > 0)
			if (!check_separator(&token, token_list, line))
				return (0);
		if (!check_value_argument(token->token_type,
					g_op_tab[opcode].arg_types[index_type_args]))
		{
			syntax_error(line->line_number, token->start_lexem_position,
										line->origin_line, INV_TYPE_ERR);
			return (0);
		}
		if ((*token_list = (*token_list)->next))
			token = lst_get_token(*token_list);
		change_value_token_type(token);
		index_type_args++;
	}
	return (1);
}
