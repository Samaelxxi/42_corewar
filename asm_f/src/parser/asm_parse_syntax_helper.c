/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_syntax_pelper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_value_argument(int token_type, unsigned arg_types)
{
	if (token_type <= 4 && token_type & arg_types)
		return (1);
	return (0);
}

void	change_value_token_type(t_token *token)
{
	if (token->token_type == TOKEN_REG)
		token->token_type = T_REG;
	else if (token->token_type == TOKEN_DIR)
		token->token_type = T_DIR;
	else if (token->token_type == TOKEN_IND)
		token->token_type = T_IND;
}

int		check_separator(t_token **token, t_list **token_list,
											t_line_of_tokens *line)
{
	int err_position;

	if ((*token)->token_type == TOKEN_SEPARATOR)
	{
		if ((*token_list = (*token_list)->next))
			if ((*token = lst_get_token(*token_list)))
			{
				change_value_token_type(*token);
				return (1);
			}
		err_position = (*token)->start_lexem_position +
						(int)ft_strlen((*token)->token_string);
		syntax_error(line->line_number, err_position,
							line->origin_line, NOT_ENOUGH_ARGS);
		return (0);
	}
	syntax_error(line->line_number, (*token)->start_lexem_position,
									line->origin_line, NOT_SEPARATOR);
	return (0);
}
