/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instruction_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:38:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/22 12:38:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_process_execution.h"
#include "vm_memory_ops.h"

t_player	*get_player_by_code(uint8_t player_code[4], t_list *players)
{
	t_player *player;

	while (players)
	{
		player = lst_get_player(players);
		if (ft_memcmp(player_code, player->player_code, REG_SIZE) == 0)
			return (player);
		players = players->next;
	}
	return (NULL);
}

uint32_t	bytes_to_number(uint8_t *bytes, unsigned size)
{
	uint32_t num;
	unsigned byte_idx;

	num = 0;
	byte_idx = 0;
	while (size)
		num += bytes[byte_idx++] << (--size * 8);
	return (num);
}

uint32_t	get_indirect_bytes(uint8_t field[MEM_SIZE], t_process *proc, unsigned arg_idx)
{
	uint64_t bytes_pc;
	uint8_t buf[REG_SIZE];
	short pc_shift;

	pc_shift = bytes_to_number(proc->comm.args[arg_idx], IND_SIZE);
	if (is_command_long(proc->comm.opcode))
		bytes_pc = (proc->pc + pc_shift) % MEM_SIZE;
	else
		bytes_pc = (proc->pc + pc_shift % IDX_MOD) % MEM_SIZE;
	read_bytes_from_field(buf, bytes_pc, REG_SIZE, field);
	return (bytes_to_number(buf, REG_SIZE));
}

int			is_command_long(uint8_t opcode)
{
	return (opcode == 0x0d || opcode == 0x0e || opcode == 0x0f);
}

uint32_t	get_arg_as_number(t_vm *vm, unsigned arg_idx, t_process *proc)
{
	uint8_t  arg_type;

	arg_type = get_arg_encoding(proc->comm.encode_byte, arg_idx);
	if (arg_type == REG_CODE)
		return (bytes_to_number(proc->registers[proc->comm.args[arg_idx][0]], REG_SIZE));
	else if (arg_type == IND_CODE)
		return get_indirect_bytes(vm->byte_field, proc, arg_idx);
	else
	{
		if (g_op_tab[proc->comm.opcode].is_index)
			return (short) bytes_to_number(proc->comm.args[arg_idx], IND_SIZE);
		else
			return bytes_to_number(proc->comm.args[arg_idx], DIR_SIZE);
	}
}

void		write_val_to_reg(uint8_t reg[REG_SIZE], uint32_t value)
{
	unsigned byte_idx;

	byte_idx = 0;
	while (byte_idx < REG_SIZE)
	{
		reg[byte_idx] = value >> (8 * (3 - byte_idx)) & 0xFF;
		byte_idx++;
	}
}

void		instr_store_bytes_on_field(t_vm *vm, unsigned store_pc, uint8_t bytes[REG_SIZE], t_process *proc)
{
	int color;

	write_bytes_on_field(vm->byte_field, store_pc, bytes, REG_SIZE);
	if (vm->vm_mode.mode == VIS_MODE)
	{
		color = vis_get_player_color(proc->player_code);
		vis_put_bytes_on_screen(color, store_pc, bytes, REG_SIZE);
		vis_mark_color_field(vm->vis.color_field, color, store_pc, REG_SIZE);
	}
}
