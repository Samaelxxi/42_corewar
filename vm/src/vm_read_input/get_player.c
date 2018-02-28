/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_magic_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:50:43 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/14 12:50:47 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_structs.h"
#include "vm.h"
#include "read_input.h"

t_player		*get_player(char *filename)
{
	t_player	*player;
	t_bytecode	*bytecode;

	if (!(bytecode = read_player(filename)))
		return (0);
	if (!is_valid_bytecode(bytecode, filename))
		return (0);
	if (!(player = create_player(bytecode)))
	{
		free_bytecode(bytecode);
		return (0);
	}
	free_bytecode(bytecode);
	return (player);
}

t_player 		*create_player(t_bytecode *bytecode)
{
	t_player	*player;

	if (!bytecode)
		return (0);
	player = ft_memalloc(sizeof(t_player));
	ft_memcpy(player->name, &bytecode->code[MAGIC_VALUE_SIZE], PROG_NAME_LENGTH);
	ft_memcpy(player->comment, &bytecode->code[MAGIC_VALUE_SIZE +
											   PROG_NAME_LENGTH + PADDING_AFTER_PROG_NAME_SIZE + CODE_SIZE], COMMENT_LENGTH);
	player->bytecode = malloc(sizeof(t_bytecode));
	player->bytecode->size = bytecode->size - g_header_size;
	player->bytecode->code = malloc(player->bytecode->size);
	ft_memcpy(player->bytecode->code, &bytecode->code[g_header_size], player->bytecode->size);
	return (player);
}

int 			is_valid_bytecode(t_bytecode *bytecode, char *filename)
{
	unsigned	func_idx;
	unsigned	value;

	func_idx = 0;
	while (g_checking_funcs[func_idx].checking_func)
	{
		if (!g_checking_funcs[func_idx].checking_func(bytecode, &value))
		{
			g_checking_funcs[func_idx].error_handler(bytecode, filename, value);
			return (0);
		}
		func_idx++;
	}
	return (1);
}

int 			is_correct_magic_value(t_bytecode *bytecode, unsigned *value)
{
	(void)value;
	if (swap_uint32(*(uint32_t *)bytecode->code) == COREWAR_EXEC_MAGIC)
		return (1);
	return (0);
}

int 			is_correct_header(t_bytecode *bytecode, unsigned *value)
{
	(void)value;
	if (bytecode->size < g_header_size)
		return (0);
	return (1);
}


int 			is_correct_size(t_bytecode *bytecode, unsigned *value)
{
	uint32_t		program_size;

	(void)value;
	program_size = bytecode->size - g_header_size;
	program_size = swap_uint32(program_size);
	if (!ft_memcmp((uint8_t *)&program_size,
				   &bytecode->code[MAGIC_VALUE_SIZE + PROG_NAME_LENGTH + PADDING_AFTER_PROG_NAME_SIZE], 4))
		return (1);
	return (0);
}

int				is_correct_max_size(t_bytecode *bytecode, unsigned *value)
{
	uint32_t		program_size;

	program_size = bytecode->size - g_header_size;
	if (program_size > CHAMP_MAX_SIZE)
	{
		*value = program_size;
		return (0);
	}
	return (1);
}
