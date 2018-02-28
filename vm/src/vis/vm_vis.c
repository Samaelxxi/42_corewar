/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_vis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 09:43:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/18 09:43:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	proceed_vis_mode(t_vm *vm)
{
	int draw_comm;

	draw_comm = 0;
	while (draw_comm == COMM_WAIT)
		draw_comm = vis_process_key_input(vm);
	vis_update_screen(vm);
}

void	vis_update_screen(t_vm *vm)
{
	vis_clear_processes_on_screen(vm);
	vis_mark_processes(vm);
	vis_cycle_update(vm);
	if (vm->current_cycle == 0)
		vis_update_c_to_die_string(vm->cycles_to_die);
	if (vm->vis.debug_on)
		vis_process_debug_mode(vm);
}

void	vis_cycle_update(t_vm *vm)
{
	vis_update_proc_string(ft_lstlen(vm->processes));
	attron(COLOR_PAIR(LABEL_COLOR));
	vis_update_cycle_string(vm->current_cycle);
	mvaddnbr(g_label_info[TOTAL_CYCLES][1], g_label_info[TOTAL_CYCLES][0],
				vm->total_cycles);
	attroff(COLOR_PAIR(LABEL_COLOR));
	vis_update_last_player_string(vm->last_player);
}
