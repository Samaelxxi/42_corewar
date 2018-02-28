/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_one_instr_to_bytecode.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_translate_instr	*translate_one_instr(t_parsed_command *command,
				t_list *dictionary_lables, unsigned start_position_instr)
{
	unsigned			free_position;
	t_translate_instr	*new_instr;

	free_position = 0;
	new_instr = (t_translate_instr*)malloc(sizeof(t_translate_instr));
	new_instr->size_instr = get_size_instruction(command);
	new_instr->instruction = (uint8_t *)malloc(sizeof(uint8_t) *
											new_instr->size_instr);
	new_instr->start_position_instr = start_position_instr;
	put_byte_opcode_to_instruction(new_instr->instruction,
									command, &free_position);
	put_byte_coding_to_instruction(new_instr->instruction,
									command, &free_position);
	put_bytes_args_to_instruction(new_instr, command,
								free_position, dictionary_lables);
	return (new_instr);
}

void				put_byte_opcode_to_instruction(uint8_t *instruction,
				t_parsed_command *command, unsigned *free_position)
{
	instruction[*free_position] = get_opcode_instr(command->command_str);
	*free_position = *free_position + 1;
}

void				put_byte_coding_to_instruction(uint8_t *instruction,
				t_parsed_command *command, unsigned *free_position)
{
	if (command->args_type != 0)
	{
		instruction[*free_position] = command->args_type;
		*free_position = *free_position + 1;
	}
}

void				put_bytes_args_to_instruction(t_translate_instr *inst_code,
t_parsed_command *command, unsigned free_position, t_list *dictionary_lables)
{
	int			index_arg;

	index_arg = 0;
	while (index_arg < MAX_NUM_OF_ARG && (command->arg_strs)[index_arg])
	{
		if (get_arg_encoding(command->args_type, index_arg) == REG_CODE)
			add_reg_arg_to_instruction(inst_code,
						(command->arg_strs)[index_arg], &free_position);
		else if (get_arg_encoding(command->args_type, index_arg) == DIR_CODE ||
														command->args_type == 0)
			if (g_op_tab[get_opcode_instr(command->command_str)].is_index == 1)
				add_dir2_arg_to_instruction(inst_code,
			(command->arg_strs)[index_arg], &free_position, dictionary_lables);
			else
				add_dir4_arg_to_instruction(inst_code,
			(command->arg_strs)[index_arg], &free_position, dictionary_lables);
		else if (get_arg_encoding(command->args_type, index_arg) == IND_CODE)
			add_ind_arg_to_instruction(inst_code,
			(command->arg_strs)[index_arg], &free_position, dictionary_lables);
		index_arg++;
	}
}
