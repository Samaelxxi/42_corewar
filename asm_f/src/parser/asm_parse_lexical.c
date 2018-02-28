/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_lexical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:04:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/17 20:04:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parsing_error			*check_lex_one_token(t_token *token, t_list *head_lines)
{
	t_parsing_error		*err;

	err = NULL;;
	if (token->token_type == TOKEN_IND)
		if ((err = check_ind_token(token, head_lines)))
			return (err);
	if (token->token_type == TOKEN_INSTR)
		if ((err = check_instr_token(token)))
			return (err);
	if (token->token_type == TOKEN_DIR)
		if ((err = check_dir_token(token, head_lines)))
			return (err);
	return (err);
}

t_parsing_error 		*check_ind_token(t_token *token, t_list *head_lines)
{
	char 			*token_str;
	t_parsing_error *err;

	token_str = token->token_string;
	while (*token_str)
	{
		if (*token_str == ':')
		{
			if (search_same_label(token_str + 1, head_lines))
				return (NULL);
			else
			{
				err = init_error_struct(IND_LABEL_ERROR, token);
				return (err);
			}
		}
		token_str++;
	}
	return (NULL);
}

int						get_opcode_instr(char *token_str)
{
	int	i;

	i = 1;
	while (i < MAX_COMMS_NUM)
	{
		if (!ft_strcmp(token_str, g_op_tab[i].name))
			return (i);
		i++;
	}
	return (0);
}

t_parsing_error			*check_instr_token(t_token *token)
{
	t_parsing_error *err;

	err = NULL;
	if (!get_opcode_instr(token->token_string))
		err = init_error_struct(INSTR_ERROR, token);
	return (err);
}

t_parsing_error			*check_dir_token(t_token *token, t_list *head_lines)
{
	char 			*token_str;
	t_parsing_error *err;

	token_str = token->token_string + 1;
	while (*token_str)
	{
		if (*token_str == ':')
		{
			if (search_same_label(token_str + 1, head_lines))
				return (NULL);
			else
			{
				err = init_error_struct(DIR_LABEL_ERROR, token);
				return (err);
			}
		}
		token_str++;
	}
	return (NULL);
}
