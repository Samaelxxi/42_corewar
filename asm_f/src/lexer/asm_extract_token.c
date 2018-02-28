/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_extract_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:38:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/17 13:38:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	extract_one_token(t_line_of_tokens *head_line_token,
						  char *line, unsigned int *pos)
{
	int 			state;
	char			*token_str;
	size_t			line_len;
	unsigned int 	start_pos;

	state = 0;
	line_len = ft_strlen(line);
	if (line[*pos] == '#')
		return ;
	start_pos = *pos;
	while ((size_t)*pos <= line_len)
	{
		state = g_table[state][search_state_column(line[*pos])];
		if (state > MIN_TOKEN_VALUE)
		{
			token_str = ft_strsub(line, start_pos, (size_t)(*pos - start_pos));
			write_token_in_list(head_line_token, state, start_pos, token_str);
			if (state == TOKEN_ERROR && line[*pos] != COMMENT_CHAR && line[*pos])
				(*pos)++;
			break ;
		}
		(*pos)++;
	}
}

int 	search_state_column(char symbol)
{
	if (symbol == ' ' || symbol == '\t')
		return(0);
	else if (symbol == '%')
		return(1);
	else if (symbol == '-')
		return(2);
	else if (symbol == ',')
		return(3);
	else if (symbol == '\0' || symbol == '#')
		return(4);
	else if (symbol == ':')
		return(5);
	else if (symbol == 'r')
		return (8);
	else if (ft_isalpha(symbol) || symbol == '_')
		return(6);
	else if (ft_isdigit(symbol))
		return (7);
	else
		return (9);
}

void	write_token_in_list(t_line_of_tokens *head_line_token,
							int token_num, unsigned int start_token, char *token_string)
{
	t_token	*new_token;

	new_token = ft_memalloc(sizeof(t_token));
	new_token->token_type = token_num;
	new_token->token_string = token_string;
	new_token->start_lexem_position = start_token + 1;
	lst_add_token(&(head_line_token->tokens), new_token);
}
