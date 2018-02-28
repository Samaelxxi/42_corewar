/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:00:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:00:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "globals.h"
#include "structs.h"
#include "vm_structs.h"
#include "vm_globals.h"

t_input_data	*read_input_data(int argc, char **argv);
void			set_mode(t_vm_mode *vm_mode, t_list *args);
t_vm			*init_vm(t_input_data *data);
void			run_vm(t_vm *vm);
void			free_data(t_vm *vm, t_input_data *args);

void			print_memory_field(uint8_t *field);
uint32_t		swap_uint32(uint32_t value);

#endif
