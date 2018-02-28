/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_file_to_bytecode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:39:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/20 16:39:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			file_to_bytecode(t_file_of_tokens *header, t_champ_commands *champ_cmd)
{
	init_champ_commands(header, &champ_cmd);
	fill_champ_commands(header->lines, champ_cmd);
	ft_lst_reverse(&champ_cmd->commands);
}

void			fill_champ_commands(t_list *lines, t_champ_commands *champ_cmd)
{
	while (lines)
	{
		line_to_commands(lst_get_line_token(lines), champ_cmd);
		lines = lines->next;
	}
}

void			line_to_commands(t_line_of_tokens *line, t_champ_commands *champ_cmd)
{
	t_token *tmp_token;
	t_list	*copy_line;


	tmp_token = lst_get_token(line->tokens);
	if (tmp_token->token_type == TOKEN_LABEL)
	{
		create_label_cmd(tmp_token, &champ_cmd->commands);
		copy_line = line->tokens->next;
		if (copy_line)
			create_standart_cmd(copy_line, &champ_cmd->commands);
	}
	else
		create_standart_cmd(line->tokens, &champ_cmd->commands);
}

void			create_label_cmd(t_token *token, t_list **commands)
{
	t_parsed_command *label_command;

	label_command = ft_memalloc(sizeof(t_parsed_command));
	label_command->command_str = token->token_string;
	label_command->args_type = 0;
	label_command->arg_strs = NULL;
	label_command->is_label = 1;
	lst_add_command(commands, label_command);
}

void			create_standart_cmd(t_list *line, t_list **commands)
{
	t_parsed_command	*standart_command;

	standart_command = ft_memalloc(sizeof(t_parsed_command));
	standart_command->command_str = lst_get_token(line)->token_string;
	standart_command->args_type = extract_coding_byte(line);
	standart_command->arg_strs = ft_memalloc(sizeof(char*) * (MAX_NUM_OF_ARG + 1));
	fill_arg_strs(line, standart_command);
	standart_command->is_label = 0;
	lst_add_command(commands, standart_command);
}
