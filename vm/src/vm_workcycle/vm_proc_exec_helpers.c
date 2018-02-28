/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_proc_exec_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:41:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/26 13:41:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_process_execution.h"

int			process_is_not_busy(t_process *proc, t_vm *vm)
{
	uint8_t code;

	code = vm->byte_field[proc->pc];
	return (proc->comm.opcode == 0 && !is_command_code(code));
}

int			is_command_code(uint8_t code)
{
	if (code > 0 && code <= COMMANDS_QUANTITY)
		return (1);
	return (0);
}

unsigned	get_arg_size(uint8_t opcode, uint8_t arg_type)
{
	if (arg_type == REG_CODE)
		return (REG_ARG_SIZE);
	else if (arg_type == IND_CODE)
		return (IND_ARG_SIZE);
	else if (arg_type == DIR_CODE)
		return ((g_op_tab[opcode].is_index) ? 2 : 4);
	else
		return (0);
}

uint8_t		get_type_by_code(uint8_t code)
{
	if (code == REG_CODE)
		return (T_REG);
	if (code == DIR_CODE)
		return (T_DIR);
	if (code == IND_CODE)
		return (T_IND);
	return (0);
}

int 		encode_byte_is_valid(t_proc_command *comm)
{
	unsigned	arg_idx;
	uint8_t		arg_type;

	if ((uint8_t)(comm->encode_byte << (2 * g_op_tab[comm->opcode].arg_num)) > 0)
		return (0);
	arg_idx = 0;
	while (arg_idx < g_op_tab[comm->opcode].arg_num)
	{
		arg_type = get_type_by_code(get_arg_encoding(comm->encode_byte, arg_idx));
		if (!(arg_type & g_op_tab[comm->opcode].arg_types[arg_idx]))
			return (0);
		arg_idx++;
	}
	return (1);
}

int 		comm_args_is_valid(t_proc_command *comm)
{
	unsigned	arg_idx;
	uint8_t		arg_type;

	arg_idx = 0;
	while (arg_idx < g_op_tab[comm->opcode].arg_num)
	{
		arg_type = get_arg_encoding(comm->encode_byte, arg_idx);
		if (arg_type == REG_CODE)
			if (comm->args[arg_idx][0] > REG_NUMBER || comm->args[arg_idx][0] == 0)
				return (0);
		arg_idx++;
	}
	return (1);
}

int			command_is_valid(t_proc_command *comm)
{
	if (!is_command_code(comm->opcode))
		return (0);
	if (g_op_tab[comm->opcode].is_encoding_byte)
	{
		if (!encode_byte_is_valid(comm))
			return (0);
		if (!comm_args_is_valid(comm))
			return (0);
	}
	return (1);
}

uint8_t 	get_encode_byte(uint8_t opcode, uint8_t byte_field[MEM_SIZE], uint32_t pc)
{
	if (g_op_tab[opcode].is_encoding_byte)
		return (get_byte_from_field(byte_field, pc + 1));
	return (0);
}
