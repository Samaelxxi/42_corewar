/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:18:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/17 15:18:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				parse_all_tokens(t_file_of_tokens *header, t_champ_commands *parsed_cmds)
{
	int		error_present;
	t_list	*line_token;

	error_present = 0;
	line_token = header->lines;
	if (!line_token)
		str_error("File don't have any instructions");
	while (line_token)
	{
		if (!check_errors_in_line(lst_get_line_token(line_token), header->lines))
			error_present = 1;
		line_token = line_token->next;
	}
	if (!error_present)
		file_to_bytecode(header, parsed_cmds);
	return (error_present);
}

int					check_errors_in_line(t_line_of_tokens *line_of_tokens, t_list *header)
{
	t_parsing_error *err;

	if ((err = check_present_token_error(line_of_tokens)))
		return (print_pars_error(err, line_of_tokens));
	if ((err = check_lexical_error(line_of_tokens, header)))
		return (print_pars_error(err, line_of_tokens));
	if (check_syntax_error(line_of_tokens))
		return (1);
	return (0);
}

t_parsing_error		*check_present_token_error(t_line_of_tokens *line_of_tokens)
{
	t_parsing_error *err;
	t_list			*tmp_token;

	tmp_token = line_of_tokens->tokens;
	while (tmp_token)
	{
		if (lst_get_token(tmp_token)->token_type == TOKEN_ERROR)
		{
			err = init_error_struct(LEXICAL_ERROR, lst_get_token(tmp_token));
			return (err);
		}
		tmp_token = tmp_token->next;
	}
	return (NULL);
}

t_parsing_error 		*check_lexical_error(t_line_of_tokens *line_of_tokens, t_list *header)
{
	t_list				*tmp_token;
	t_parsing_error		*err;

	tmp_token = line_of_tokens->tokens;
	while (tmp_token)
	{
		if ((err = check_lex_one_token(lst_get_token(tmp_token), header)))
			return (err);
		tmp_token = tmp_token->next;
	}
	return (NULL);
}
