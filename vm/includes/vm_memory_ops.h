/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_memory_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:42:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/22 11:42:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_MEMORY_OPS_H
# define VM_MEMORY_OPS_H

#include "vm_structs.h"

void		write_champions_on_field(t_vm *vm);
void		write_champion_on_field(t_vm *vm, t_player *player, unsigned player_num);
void		write_bytes_on_field(uint8_t *byte_field, unsigned write_idx,
								 const uint8_t *bytes, unsigned size);
void		write_bytecode_on_field(t_vm *vm, unsigned write_idx, t_bytecode *bytecode);

void		clear_write_bytes_lst(t_vm *vm);
void		read_bytes_from_field(uint8_t *bytes, uint32_t start,
								  uint32_t size, uint8_t byte_field[MEM_SIZE]);
uint8_t		get_byte_from_field(uint8_t byte_field[MEM_SIZE], uint32_t byte_idx);
uint32_t	get_indirect_bytes(uint8_t field[MEM_SIZE], t_process *proc, unsigned arg_idx);

t_process	*create_new_process(unsigned pc, t_player *player);
t_process	*clone_process(unsigned pc, t_process *process);
int			process_still_alive(t_process *proc, t_list *processes);
void		write_val_to_reg(uint8_t reg[REG_SIZE], uint32_t value);

#endif
