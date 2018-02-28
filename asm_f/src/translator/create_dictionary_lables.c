/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dictionary_labels.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				create_dictionary_labels(t_list **dictionary_lables,
									t_champ_commands *parsed_commands)
{
	unsigned			position_lable;
	t_list				*head_commands;
	t_page_dict_label	*page_dict_label;
	t_parsed_command	*commands;

	position_lable = 0;
	head_commands = parsed_commands->commands;
	while (head_commands)
	{
		commands = lst_get_command(head_commands);
		if (commands->is_label == 1)
		{
			page_dict_label = create_page_dict_label(position_lable,
													commands->command_str);
			lst_add_page_dict_lable(dictionary_lables, page_dict_label);
		}
		else
			position_lable = position_lable + get_size_instruction(commands);
		head_commands = head_commands->next;
	}
}

t_page_dict_label	*create_page_dict_label(unsigned position_lable,
													char *label_name)
{
	t_page_dict_label	*new_page;

	if ((new_page = (t_page_dict_label*)malloc(sizeof(t_page_dict_label))))
	{
		new_page->label_name = ft_strdup(label_name);
		*ft_strchr(new_page->label_name, LABEL_CHAR) = '\0';
		new_page->position = position_lable;
	}
	return (new_page);
}

unsigned			get_size_instruction(t_parsed_command *commands)
{
	unsigned	size_instr;
	int			opcode;

	opcode = get_opcode_instr(commands->command_str);
	size_instr = INST_SIZE + g_op_tab[opcode].is_encoding_byte +
					get_size_arguments(commands->args_type, opcode);
	return (size_instr);
}

unsigned			get_size_arguments(u_int8_t encode_byte, int opcode)
{
	unsigned	size_argument;
	int			index_arg;

	size_argument = 0;
	index_arg = 0;
	if (encode_byte != 0)
		while (index_arg < MAX_NUM_OF_ARG)
		{
			if (get_arg_encoding(encode_byte, index_arg) == REG_CODE)
				size_argument += REG_ARG_SIZE;
			else if (get_arg_encoding(encode_byte, index_arg) == DIR_CODE)
				size_argument += (g_op_tab[opcode].is_index ? 2 : 4);
			else if (get_arg_encoding(encode_byte, index_arg) == IND_CODE)
				size_argument += IND_ARG_SIZE;
			index_arg++;
		}
	else
		size_argument = (g_op_tab[opcode].is_index ? 2 : 4);
	return (size_argument);
}
