/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:01:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/18 15:01:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_put_bytes_on_screen(int color, int start_idx, uint8_t *bytes,
								unsigned size)
{
	unsigned byte_idx;

	byte_idx = 0;
	attron(COLOR_PAIR(color));
	while (byte_idx < size)
	{
		vis_put_byte_on_screen(bytes[byte_idx], start_idx + byte_idx);
		byte_idx++;
	}
	attroff(COLOR_PAIR(color));
}

void	vis_put_byte_on_screen(uint8_t byte, unsigned place_idx)
{
	char bytestr[3];

	place_idx = place_idx % MEM_SIZE;
	bytestr[0] = HEX_BASE[byte / 16];
	bytestr[1] = HEX_BASE[byte % 16];
	bytestr[2] = '\0';
	mvaddstr(place_idx / BYTES_IN_ROW + 2,
			 (place_idx % BYTES_IN_ROW) * 3 + 3, bytestr);
}

void	vis_mark_processes(t_vm *vm)
{
	t_list *processes;
	t_process *proc;
	uint8_t color;

	processes = vm->processes;
	while (processes)
	{
		proc = lst_get_process(processes);
		color = (vm->vis.color_field[proc->pc] % PROC_COLOR_SHIFT)
					+ PROC_COLOR_SHIFT;
		vm->vis.color_field[proc->pc] = color;

		attron(COLOR_PAIR(color));
		vis_put_byte_on_screen(vm->byte_field[proc->pc], proc->pc);
		attroff(COLOR_PAIR(color));
		processes = processes->next;
	}
}

void	vis_clear_processes_on_screen(t_vm *vm)
{
	unsigned byte_idx;

	byte_idx = 0;
	while (byte_idx < MEM_SIZE)
	{
		if (vm->vis.color_field[byte_idx] >= PROC_COLOR_SHIFT)
		{
			vm->vis.color_field[byte_idx] -= PROC_COLOR_SHIFT;
			attron(COLOR_PAIR(vm->vis.color_field[byte_idx]));
			vis_put_byte_on_screen(vm->byte_field[byte_idx], byte_idx);
			attroff(COLOR_PAIR(vm->vis.color_field[byte_idx]));
		}
		byte_idx++;
	}
}