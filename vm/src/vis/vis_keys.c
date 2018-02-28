/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:37:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/19 11:37:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

int		vis_process_key_input(t_vm *vm)
{
	int key;

	key = getch();
	if (key == SPACE_KEY)
		vis_pause_event(vm);
	else if (key == MINUS_KEY || key == PLUS_KEY)
		vis_change_delay_event(key, vm);
	else if (key == ENTER_KEY)
		return (COMM_NO_SKIP_DRAW);
	else if (key == DEBUG_KEY)
		vis_switch_debug_mode(vm);
	else if (key == NEXT_PROC_KEY && vm->vis.debug_on)
		vis_debug_switch_proc(vm);
	return (vm->vis.on);
}

void	vis_debug_set_neigh_proc(t_vm *vm, t_process *proc)
{
	t_list	*processes;

	processes = vm->processes;
	while (lst_get_process(processes) != proc)
		processes = processes->next;
	if (!processes || !processes->next)
		vm->vis.debug_proc = lst_get_process(vm->processes);
	else
		vm->vis.debug_proc = lst_get_process(processes->next);
}

void	vis_debug_switch_proc(t_vm *vm)
{
	t_process *cur_proc;

	if (!process_still_alive(vm->vis.debug_proc, vm->processes))
		vm->vis.debug_proc = lst_get_process(vm->processes);
	else
	{
		cur_proc = vm->vis.debug_proc;
		debug_clear_process_caret(vm);
		vis_debug_set_neigh_proc(vm, cur_proc);
	}
	vis_debug_draw_proc_data(vm->vis.debug_proc, vm);
}

void	vis_switch_debug_mode(t_vm *vm)
{
	vm->vis.debug_on = (vm->vis.debug_on + 1) % 2;
	if (vm->vis.debug_on)
	{
		vm->vis.debug_proc = lst_get_process(vm->processes);
		vis_debug_init_gui();
		vis_debug_draw_proc_data(vm->vis.debug_proc, vm);
	}
	else
	{
		vis_clear_debug_gui();
		debug_clear_process_caret(vm);
	}
}

void	vis_pause_event(t_vm *vm)
{
	vm->vis.on = (vm->vis.on + 1) % 2;
	vis_update_pause_string(vm->vis.on);
	set_timeout(vm);
}

void	vis_change_delay_event(int key, t_vm *vm)
{
	if (key == PLUS_KEY)
	{
		vm->vis.cps += 10;
		set_timeout(vm);
	}
	else if (key == MINUS_KEY)
		if (vm->vis.cps > 10)
		{
			vm->vis.cps -= 10;
			set_timeout(vm);
		}
	vis_update_delay_string(vm->vis.cps);
}
