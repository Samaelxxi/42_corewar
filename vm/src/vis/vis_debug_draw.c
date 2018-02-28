/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_debug_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:11:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/26 16:11:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_debug_draw_proc_data(t_process *proc, t_vm *vm)
{
	vis_debug_reset_gui(vm);
	vis_debug_draw_proc_caret(vm);
	vm->vis.proc_prev_pc = vm->vis.debug_proc->pc;
	vis_debug_print_proc_info(proc);
}

void	vis_debug_draw_proc_caret(t_vm *vm)
{
	attron(COLOR_PAIR(DEBUG_PROC_COLOR));
	vis_put_byte_on_screen(vm->byte_field[vm->vis.debug_proc->pc], vm->vis.debug_proc->pc);
	attroff(COLOR_PAIR(DEBUG_PROC_COLOR));
}

void	vis_debug_draw_reg(int y, int x, uint8_t reg[REG_SIZE])
{
	vis_debug_draw_byte(y, x, reg[0]);
	vis_debug_draw_byte(y, x + 3, reg[1]);
	vis_debug_draw_byte(y, x + 6, reg[2]);
	vis_debug_draw_byte(y, x + 9, reg[3]);
}

void	vis_debug_draw_byte(int y, int x, uint8_t byte)
{
	mvaddch(y, x, HEX_BASE[byte / 16]);
	mvaddch(y, x + 1, HEX_BASE[byte % 16]);
}
