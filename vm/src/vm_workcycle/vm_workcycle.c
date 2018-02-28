/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_workcycle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:29:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 13:29:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_workcycle.h"

void		run_vm(t_vm *vm)
{
	start_vm_execution(vm);
	while (vm->processes != NULL && vm->cycles_to_die > 0)
	{
		execute_processes(vm);
		go_to_next_cycle(vm);
		proceed_vm_mode(vm);
	}
	finish_vm_execution(vm);
}

void		start_vm_execution(t_vm *vm)
{
	if (vm->vm_mode.mode == NO_MODE || vm->vm_mode.mode == DUMP_MODE)
		print_introduction(vm);
	if (vm->vm_mode.mode == DUMP_MODE)
	{
		print_memory_field(vm->byte_field);
		wait_for_anykey();
	}
	else if (vm->vm_mode.mode == VIS_MODE)
		vis_init_screen(vm);
}

void		execute_processes(t_vm *vm)
{
	t_list *processes;
	t_process *process;

	processes = vm->processes;
	while (processes)
	{
		process = lst_get_process(processes);
		execute_process(process, vm);
		processes = processes->next;
	}
}

void		proceed_vm_mode(t_vm *vm)
{
	if (vm->vm_mode.mode == DUMP_MODE)
		proceed_dump_mode(vm);
	else if (vm->vm_mode.mode == VIS_MODE)
	{
		proceed_vis_mode(vm);
		clear_write_bytes_lst(vm);
	}
}

void		proceed_dump_mode(t_vm *vm)
{
	if (vm->vm_mode.arg && vm->total_cycles % vm->vm_mode.arg == 0)
	{
		print_memory_field(vm->byte_field);
		wait_for_anykey();
	}
}

void		finish_vm_execution(t_vm *vm)
{
	if (vm->vm_mode.mode != VIS_MODE)
		ft_printf("Contestant %d, \"%s\", has won !\n",
				  vm->last_player->player_num, vm->last_player->name);
	else
	{
		timeout(-1);
		vis_update_screen(vm);
		getch();
		endwin();
	}
}
