/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:31:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/21 11:31:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_process_debug_mode(t_vm *vm)
{
	if (vm->vis.debug_proc)
		if (!process_still_alive(vm->vis.debug_proc, vm->processes))
		{
			debug_clear_process_caret(vm);
			vm->vis.debug_proc = NULL;
			vm->vis.proc_prev_pc = -1;
		}
	if (vm->vis.debug_proc)
		vis_debug_draw_proc_data(vm->vis.debug_proc, vm);
}

void	vis_debug_reset_gui(t_vm *vm)
{
	vis_clear_debug_gui();
	vis_debug_init_gui();
	if (vm->vis.proc_prev_pc < MEM_SIZE)
	{
		attron(COLOR_PAIR(vm->vis.color_field[vm->vis.proc_prev_pc]));
		vis_put_byte_on_screen(vm->byte_field[vm->vis.proc_prev_pc], vm->vis.proc_prev_pc);
		attroff(COLOR_PAIR(vm->vis.color_field[vm->vis.proc_prev_pc]));;
	}
}

void	vis_debug_print_proc_info(t_process *proc)
{
	vis_debug_print_player_name(proc);
	vis_debug_print_process_instr(proc);
	vis_debug_print_proc_reg_values(proc);
}

void	vis_debug_print_player_name(t_process *proc)
{
	init_pair(66, g_player_colors[vis_get_player_color(proc->player_code) - 1],
			  COLOR_WHITE);
	attron(COLOR_PAIR(66));
	vis_debug_draw_reg(DEBUG_LY + 3, DEBUG_LX + 18, proc->player_code);
	attroff(COLOR_PAIR(66));
}

void	vis_debug_print_process_instr(t_process *proc)
{
	attron(COLOR_PAIR(DEBUG_LABEL_COLOR));
	if (proc->comm.opcode)
		mvaddstr(DEBUG_LY + 5, DEBUG_LX + 23,  g_op_tab[proc->comm.opcode].name);
	else
		mvaddstr(DEBUG_LY + 5, DEBUG_LX + 23, "IDLE");
	mvaddnbr(DEBUG_LY + 6, DEBUG_LX + 23, proc->comm.exec_counter);
	mvaddnbr(DEBUG_LY + 7, DEBUG_LX + 23, proc->carry);
	attroff(COLOR_PAIR(DEBUG_LABEL_COLOR));
}

void	debug_clear_process_caret(t_vm *vm)
{
	unsigned byte_idx;

	byte_idx = vm->vis.proc_prev_pc;
	if (byte_idx < MEM_SIZE)
	{
		attron(COLOR_PAIR(vm->vis.color_field[byte_idx]));
		vis_put_byte_on_screen(vm->byte_field[byte_idx], byte_idx);
		attroff(COLOR_PAIR(vm->vis.color_field[byte_idx]));
	}
}

void	vis_debug_print_proc_reg_values(t_process *proc)
{
	int reg_num;

	reg_num = 0;
	attron(COLOR_PAIR(DEBUG_LABEL_COLOR));
	while (reg_num < REG_NUMBER)
	{
		vis_debug_draw_reg(DEBUG_LY + 10 + reg_num / 2,  // interface magic
						   DEBUG_LX + 6 + reg_num % 2 * 17 + reg_num % 2,
						   proc->registers[reg_num + 1]);
		reg_num++;
	}
	attroff(COLOR_PAIR(DEBUG_LABEL_COLOR));
}

void	vis_clear_debug_gui(void)
{
	int row;
	int col;

	row = 0;
	while (row < DEBUG_HEIGHT)
	{
		col = 0;
		while (col < DEBUG_WIDTH)
			mvaddch(DEBUG_LY + row, DEBUG_LX + col++, ' ');
		row++;
	}
}

