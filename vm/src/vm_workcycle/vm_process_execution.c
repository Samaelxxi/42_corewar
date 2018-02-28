/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_commands.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:24:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 16:24:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_process_execution.h"

void		execute_process(t_process *proc, t_vm *vm)
{
	if (process_is_not_busy(proc, vm))
		proc->pc++;
	else
	{
		if (proc->comm.exec_counter > 0)
			proc->comm.exec_counter--;
		if (proc->comm.opcode == 0)
		{
			load_command_to_process(proc, vm);
			proc->comm.exec_counter--;
		}
		else if (proc->comm.exec_counter == 0)
			process_command(proc, vm);
	}
	proc->pc %= MEM_SIZE;
}

void		load_command_to_process(t_process *proc, t_vm *vm)
{
	uint8_t		opcode;

	opcode = vm->byte_field[proc->pc];
	if (!is_command_code(opcode))
		return;
	proc->comm.opcode = opcode;
	proc->comm.exec_counter = g_op_tab[opcode].cycles;
	proc->comm.encode_byte = get_encode_byte(opcode, vm->byte_field, proc->pc);
	read_comm_args(proc, vm->byte_field);
}

void		process_command(t_process *proc, t_vm *vm)
{
	proc->comm.encode_byte = get_encode_byte(proc->comm.opcode, vm->byte_field, proc->pc);
	read_comm_args(proc, vm->byte_field);
	if (command_is_valid(&(proc->comm)))
		execute_command(proc, vm);
	proc->pc += calc_command_size_on_field(&(proc->comm));
	ft_memset(&(proc->comm), 0, sizeof(t_proc_command));
}

unsigned	calc_command_size_on_field(t_proc_command *comm)
{
	unsigned comm_size;

	comm_size = 1;
	comm_size += g_op_tab[comm->opcode].is_encoding_byte;
	if (g_op_tab[comm->opcode].is_encoding_byte)
		comm_size += calc_args_size(comm->opcode, comm->encode_byte);
	else
		comm_size += ((g_op_tab[comm->opcode].is_index) ? 2 : 4);
	return (comm_size);
}

unsigned	calc_args_size(uint8_t opcode, uint8_t enc_byte)
{
	unsigned arg_idx;
	unsigned args_size;
	uint8_t arg_type;

	args_size = 0;
	arg_idx = 0;
	while (arg_idx < g_op_tab[opcode].arg_num)
	{
		arg_type = get_arg_encoding(enc_byte, arg_idx);
		args_size += get_arg_size(opcode, arg_type);
		arg_idx++;
	}
	return (args_size);
}

void		read_comm_args(t_process *proc, uint8_t byte_field[MEM_SIZE])
{
	uint32_t	start;
	uint32_t	size;
	uint8_t		arg_idx;

	start = proc->pc + g_op_tab[proc->comm.opcode].is_encoding_byte + 1;
	if (!g_op_tab[proc->comm.opcode].is_encoding_byte)
	{
		read_bytes_from_field(proc->comm.args[0], start,
							  get_arg_size(proc->comm.opcode, DIR_CODE), byte_field);
		return ;
	}
	arg_idx = 0;
	while (arg_idx < g_op_tab[proc->comm.opcode].arg_num)
	{
		size = get_arg_size(proc->comm.opcode,
							(get_arg_encoding(proc->comm.encode_byte, arg_idx)));
		read_bytes_from_field(proc->comm.args[arg_idx], start, size, byte_field);
		start += size;
		arg_idx++;
	}
}

