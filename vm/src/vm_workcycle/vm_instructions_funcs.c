/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:32:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/17 18:32:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_process_execution.h"

void		execute_command(t_process *proc, t_vm *vm)
{
	int carry_mod;

	carry_mod = g_comm_funcs[proc->comm.opcode](proc, vm);
	if (carry_mod != NOT_MODIFY_CARRY)
		proc->carry = carry_mod;
}

int			live_comm(t_process *proc, t_vm *vm)
{
	t_player *player;
	proc->lives += 1;
	player = get_player_by_code(proc->comm.args[0], vm->players);
	if (player)
		vm->last_player = player;
	return (NOT_MODIFY_CARRY);
}

int			ld_comm(t_process *proc, t_vm *vm)
{
	uint32_t value;
	t_proc_command *comm;

	comm = &(proc->comm);
	value = get_arg_as_number(vm, 0, proc);
	write_val_to_reg(proc->registers[comm->args[1][0]], value);
	return (value == 0 ? 1 : 0);
}

int			st_comm(t_process *proc, t_vm *vm)
{
	unsigned store_pc;
	short pc_shift;
	uint8_t bytes[REG_SIZE];
	t_proc_command *comm;

	comm = &(proc->comm);
	if (get_arg_encoding(proc->comm.encode_byte, 1) == REG_CODE)
		ft_memcpy(proc->registers[comm->args[1][0]],
					proc->registers[comm->args[0][0]],
					REG_SIZE);
	else
	{
		pc_shift = bytes_to_number(comm->args[1], IND_SIZE);
		store_pc = (proc->pc + pc_shift % IDX_MOD) % MEM_SIZE;
		ft_memcpy(bytes, proc->registers[comm->args[0][0]], REG_SIZE);
		instr_store_bytes_on_field(vm, store_pc, bytes, proc);
	}
	return (NOT_MODIFY_CARRY);
}

int			add_comm(t_process *proc, t_vm *vm)
{
	t_proc_command *comm;
	uint32_t value1;
	uint32_t value2;
	uint32_t sum;

	(void)vm;
	comm = &(proc->comm);

	value1 = bytes_to_number(proc->registers[comm->args[0][0]], REG_SIZE);
	value2 = bytes_to_number(proc->registers[comm->args[1][0]], REG_SIZE);
	sum = value1 + value2;
	write_val_to_reg(proc->registers[comm->args[2][0]], sum);

	return (sum == 0 ? 1 : 0);
}

int			sub_comm(t_process *proc, t_vm *vm)
{
	t_proc_command *comm;
	uint32_t value1;
	uint32_t value2;
	uint32_t diff;

	(void)vm;
	comm = &(proc->comm);

	value1 = bytes_to_number(proc->registers[comm->args[0][0]], REG_SIZE);
	value2 = bytes_to_number(proc->registers[comm->args[1][0]], REG_SIZE);
	diff = value1 - value2;
	write_val_to_reg(proc->registers[comm->args[2][0]], diff);

	return (diff == 0 ? 1 : 0);
}

int			and_comm(t_process *proc, t_vm *vm)
{
	t_proc_command *comm;
	uint32_t value1;
	uint32_t value2;
	uint32_t res;

	(void)vm;
	comm = &(proc->comm);

	value1 = get_arg_as_number(vm, 0, proc);
	value2 = get_arg_as_number(vm, 1, proc);
	res = value1 & value2;
	write_val_to_reg(proc->registers[comm->args[2][0]], res);

	return (res == 0 ? 1 : 0);
}

int			or_comm(t_process *proc, t_vm *vm)
{
	t_proc_command *comm;
	uint32_t value1;
	uint32_t value2;
	uint32_t res;

	(void)vm;
	comm = &(proc->comm);

	value1 = get_arg_as_number(vm, 0, proc);
	value2 = get_arg_as_number(vm, 1, proc);
	res = value1 | value2;
	write_val_to_reg(proc->registers[comm->args[2][0]], res);

	return (res == 0 ? 1 : 0);
}

int			xor_comm(t_process *proc, t_vm *vm)
{
	t_proc_command *comm;
	uint32_t value1;
	uint32_t value2;
	uint32_t res;

	(void)vm;
	comm = &(proc->comm);

	value1 = get_arg_as_number(vm, 0, proc);
	value2 = get_arg_as_number(vm, 1, proc);
	res = value1 ^ value2;
	write_val_to_reg(proc->registers[comm->args[2][0]], res);

	return (res == 0 ? 1 : 0);
}

int			zjmp_comm(t_process *proc, t_vm *vm)
{
	short pc_shift;

	(void)(vm);
	if (proc->carry)
	{
		pc_shift = bytes_to_number(proc->comm.args[0], 2);
		proc->pc = (proc->pc + (pc_shift % IDX_MOD) - ZJMP_BYTE_SIZE) % MEM_SIZE;
	}
	return (NOT_MODIFY_CARRY);
}

int			ldi_comm(t_process *proc, t_vm *vm)
{
	uint32_t val1;
	uint32_t val2;
	uint32_t read_pc;
	t_proc_command *comm;
	int pc_shift;

	comm = &(proc->comm);
	val1 = get_arg_as_number(vm, 0, proc);
	val2 = get_arg_as_number(vm, 1, proc);
	pc_shift = val1 + val2;
	read_pc = proc->pc + pc_shift % IDX_MOD;
	read_bytes_from_field(proc->registers[comm->args[2][0]],
						  read_pc, REG_SIZE, vm->byte_field);
	return (NOT_MODIFY_CARRY);
}

int			sti_comm(t_process *proc, t_vm *vm)
{
	unsigned store_pc;
	int pc_shift;
	uint8_t bytes[4];
	t_proc_command *comm;

	comm = &(proc->comm);
	pc_shift = (get_arg_as_number(vm, 1, proc) + get_arg_as_number(vm, 2, proc));
	store_pc = (proc->pc + pc_shift % IDX_MOD) % MEM_SIZE;
	ft_memcpy(bytes, proc->registers[comm->args[0][0]], REG_SIZE);
	instr_store_bytes_on_field(vm, store_pc, bytes, proc);
	return (NOT_MODIFY_CARRY);
}

int			fork_comm(t_process *proc, t_vm *vm)
{
	t_process *new_proc;
	short pc_shift;
	unsigned proc_pc;

	pc_shift = bytes_to_number(proc->comm.args[0], 2);
	proc_pc = (proc->pc + pc_shift % IDX_MOD) % MEM_SIZE;
	new_proc = clone_process(proc_pc, proc);
	lst_append_process(&(vm->processes), new_proc);
	return (NOT_MODIFY_CARRY);
}

int			lld_comm(t_process *proc, t_vm *vm)
{
	return (ld_comm(proc, vm));
}

int			lldi_comm(t_process *proc, t_vm *vm)
{
	uint32_t val1;
	uint32_t val2;
	uint32_t read_pc;
	t_proc_command *comm;
	int pc_shift;

	comm = &(proc->comm);
	val1 = get_arg_as_number(vm, 0, proc);
	val2 = get_arg_as_number(vm, 1, proc);
	pc_shift = val1 + val2;
	read_pc = proc->pc + pc_shift;
	read_bytes_from_field(proc->registers[comm->args[2][0]],
						  read_pc, REG_SIZE, vm->byte_field);
	return (((uint32_t)(proc->registers[comm->args[2][0]] == 0)) ? 1 : 0);
}

int			lfork_comm(t_process *proc, t_vm *vm)
{
	t_process *new_proc;
	short pc_shift;
	unsigned proc_pc;

	pc_shift = bytes_to_number(proc->comm.args[0], 2);
	proc_pc = (proc->pc + pc_shift) % MEM_SIZE;
	new_proc = clone_process(proc_pc, proc);
	lst_append_process(&(vm->processes), new_proc);
	return (NOT_MODIFY_CARRY);
}

int			aff_comm(t_process *proc, t_vm *vm)
{
	uint8_t *reg;
	t_player *player;

	player = get_player_by_code(proc->player_code, vm->players);
	reg = proc->comm.args[0];
	if (vm->vm_mode.mode != VIS_MODE)
		ft_printf("Player %s said: \"%c%c%c%c\"\n", player->name,
					reg[0], reg[1], reg[2], reg[3]);
	return (NOT_MODIFY_CARRY);
}
