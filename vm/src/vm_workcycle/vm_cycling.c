/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:15:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/17 20:15:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_workcycle.h"

void		go_to_next_cycle(t_vm *vm)
{
	vm->current_cycle++;
	vm->total_cycles++;
	if (vm->current_cycle == vm->cycles_to_die)
		vm_finish_period(vm);
}

void		vm_finish_period(t_vm *vm)
{
	vm->current_cycle = 0;
	vm->noeffect_checks++;
	if (vm->noeffect_checks >= MAX_CHECKS ||
			live_calls_sum(vm->processes) >= NBR_LIVE)
		reduce_cycles_to_die(vm);
	kill_weak_processes(&(vm->processes));
	reset_process_lives(vm->processes);
}

void		reset_process_lives(t_list *processes)
{
	t_process *proc;

	while (processes)
	{
		proc = lst_get_process(processes);
		proc->lives = 0;
		processes = processes->next;
	}
}

int			live_calls_sum(t_list *processes)
{
	int live_calls;
	t_process *process;

	live_calls = 0;
	while (processes)
	{
		process = lst_get_process(processes);
		live_calls += process->lives;
		processes = processes->next;
	}

	return (live_calls);
}

void		reduce_cycles_to_die(t_vm *vm)
{
	vm->noeffect_checks = 0;
	vm->cycles_to_die -= CYCLE_DELTA;
	if ((int)(vm->cycles_to_die) < 0)
		vm->cycles_to_die = 0;
}

void		kill_weak_processes(t_list **processes)
{
	ft_list_remove_if(processes, is_process_dead, process_deleter);
}

int			is_process_dead(t_list *node)
{
	t_process *proc;

	proc = lst_get_process(node);

	if (proc->lives == 0)
		return (1);
	return (0);
}
