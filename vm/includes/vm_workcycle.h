/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_workcycle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:50:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 13:50:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_WORKCYCLE_H
# define VM_WORKCYCLE_H

#include "vm.h"
#include "vm_memory_ops.h"

void		start_vm_execution(t_vm *vm);
void		print_introduction(t_vm *vm);

void		execute_processes(t_vm *vm);
void		execute_process(t_process *proc, t_vm *vm);

void		go_to_next_cycle(t_vm *vm);
void		vm_finish_period(t_vm *vm);
int			live_calls_sum(t_list *processes);
void		reduce_cycles_to_die(t_vm *vm);
void		kill_weak_processes(t_list **processes);
int			is_process_dead(t_list *node);
void		reset_process_lives(t_list *processes);

void		proceed_vm_mode(t_vm *vm);
void		proceed_dump_mode(t_vm *vm);
void		proceed_vis_mode(t_vm *vm);
void		vis_init_screen(t_vm *vm);

void		finish_vm_execution(t_vm *vm);

#endif
