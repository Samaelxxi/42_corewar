/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champion_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		create_champion_code(t_champion *champion,
								t_champ_commands *parsed_commands)
{
	t_list		*dictionary_lables;

	dictionary_lables = NULL;
	champion->champ_name = translate_string_to_bytecode(
	parsed_commands->champ_name, PROG_NAME_LENGTH +
								PADDING_AFTER_PROG_NAME_SIZE);
	champion->champ_desc = translate_string_to_bytecode(
	parsed_commands->champ_desc, COMMENT_LENGTH + PADDING_AFTER_COMMENT_SIZE);
	champion->magic_value = translate_usign_value_to_bytecode(
											COREWAR_EXEC_MAGIC);
	champion->bytecode = ft_memalloc(sizeof(t_bytecode));
	create_dictionary_labels(&dictionary_lables, parsed_commands);
	translate_instr_to_bytecode(champion, dictionary_lables, parsed_commands);
	champion->size_champ = translate_usign_value_to_bytecode(
									(champion->bytecode)->size);
	free_dict_lables(dictionary_lables);
}

u_int8_t	*translate_string_to_bytecode(char *string, size_t str_size)
{
	u_int8_t	*res;

	res = (u_int8_t*)ft_memalloc(str_size);
	ft_memcpy(res, string, ft_strlen(string));
	return (res);
}

uint8_t		*translate_usign_value_to_bytecode(unsigned value)
{
	u_int8_t	*res;

	res = (u_int8_t*)malloc(sizeof(unsigned));
	value = swap_uint32(value);
	ft_memcpy(res, &value, 4);
	return (res);
}

void		translate_instr_to_bytecode(t_champion *champion,
			t_list *dictionary_lables, t_champ_commands *parsed_commands)
{
	t_translate_instr	*inst_code;
	t_list				*commands;
	t_parsed_command	*command;

	commands = parsed_commands->commands;
	while (commands)
	{
		command = lst_get_command(commands);
		if (command->is_label == 0)
		{
			inst_code = translate_one_instr(command,
			dictionary_lables, (champion->bytecode)->size);
			add_instr_to_struct_bytecode(champion, inst_code);
		}
		commands = commands->next;
	}
}

void		add_instr_to_struct_bytecode(t_champion *champion,
									t_translate_instr *inst_code)
{
	(champion->bytecode)->code = realloc((champion->bytecode)->code,
					(champion->bytecode)->size + inst_code->size_instr);
	ft_memcpy((champion->bytecode)->code + (champion->bytecode)->size,
						inst_code->instruction, inst_code->size_instr);
	(champion->bytecode)->size = (champion->bytecode)->size +
												inst_code->size_instr;
	free_struct_translate_instr(&inst_code);
}
