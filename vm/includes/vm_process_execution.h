/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:28:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/17 18:28:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_COMMANDS_H
# define VM_COMMANDS_H

# include "vm_workcycle.h"

int			process_is_not_busy(t_process *proc, t_vm *vm);
int			is_command_code(uint8_t code);
void		process_command(t_process *proc, t_vm *vm);
unsigned	calc_command_size_on_field(t_proc_command *comm);
unsigned	calc_args_size(uint8_t opcode, uint8_t enc_byte);
unsigned	get_arg_size(uint8_t opcode, uint8_t arg_type);
void		load_command_to_process(t_process *proc, t_vm *vm);
int			command_is_valid(t_proc_command *comm);
void		execute_command(t_process *proc, t_vm *vm);
void		read_comm_args(t_process *proc, uint8_t byte_field[MEM_SIZE]);
uint8_t 	get_encode_byte(uint8_t opcode, uint8_t byte_field[MEM_SIZE], uint32_t pc);
uint8_t		get_type_by_code(uint8_t code);

# define ZJMP_BYTE_SIZE 3

int			live_comm(t_process *proc, t_vm *vm);
int			ld_comm(t_process *proc, t_vm *vm);
int			st_comm(t_process *proc, t_vm *vm);
int			add_comm(t_process *proc, t_vm *vm);
int			sub_comm(t_process *proc, t_vm *vm);
int			and_comm(t_process *proc, t_vm *vm);
int			or_comm(t_process *proc, t_vm *vm);
int			xor_comm(t_process *proc, t_vm *vm);
int			zjmp_comm(t_process *proc, t_vm *vm);
int			ldi_comm(t_process *proc, t_vm *vm);
int			sti_comm(t_process *proc, t_vm *vm);
int			fork_comm(t_process *proc, t_vm *vm);
int			lld_comm(t_process *proc, t_vm *vm);
int			lldi_comm(t_process *proc, t_vm *vm);
int			lfork_comm(t_process *proc, t_vm *vm);
int			aff_comm(t_process *proc, t_vm *vm);

t_player	*get_player_by_code(uint8_t player_code[4], t_list *players);
uint32_t	get_arg_as_number(t_vm *vm, unsigned arg_idx, t_process *proc);
uint32_t	bytes_to_number(uint8_t *bytes, unsigned size);
void		instr_store_bytes_on_field(t_vm *vm, unsigned store_pc, uint8_t bytes[REG_SIZE], t_process *proc);
int			is_command_long(uint8_t opcode);


#endif
