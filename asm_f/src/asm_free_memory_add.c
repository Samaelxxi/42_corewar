/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_memory_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:29:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/26 14:29:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	line_deleter(void *content, size_t size)
{
	t_line_of_tokens *line;

	if (content && size)
	{
		line = *((t_line_of_tokens**)(content));
		free(line->origin_line);
		ft_lstdel(&(line->tokens), token_deleter);
		free(line);
		free(content);
	}
}

void	token_deleter(void *content, size_t size)
{
	t_token *token;

	if (content && size)
	{
		token = *((t_token**)(content));
		free(token->token_string);
		free(token);
		free(content);
	}
}

void	command_deleter(void *content, size_t size)
{
	t_parsed_command *command;

	if (content && size)
	{
		command = *((t_parsed_command**)(content));
		if (command->arg_strs)
			free(command->arg_strs);
		free(command);
		free(content);
	}
}

void	free_dict_lables(t_list *dictionary_lables)
{
	if (dictionary_lables)
		ft_lstdel(&(dictionary_lables), label_deleter);
}

void	label_deleter(void *content, size_t size)
{
	t_page_dict_label *label;

	if (content && size)
	{
		label = *((t_page_dict_label**)(content));
		free(label->label_name);
		free(label);
		free(content);
	}
}
