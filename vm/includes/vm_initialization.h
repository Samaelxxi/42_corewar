/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialization.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:45:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:45:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_INITIALIZATION_H
# define VM_INITIALIZATION_H

#include "vm_structs.h"
#include "vm_globals.h"
#include "vm_memory_ops.h"

void		init_vm_values(t_vm *vm, t_input_data *data);
t_player	*get_last_player(t_list *players);

void		init_champion_processes(t_vm *vm);
void		add_champion_process(t_vm *vm, t_player *player, unsigned player_num);
void		load_command_to_process(t_process *proc, t_vm *vm);

void		choose_vm_mode(t_vm *vm, t_list *args);

#endif
