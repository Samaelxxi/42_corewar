/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:11:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/23 10:11:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_DISASM_H
# define COREWAR_DISASM_H

#include "libft.h"
#include "vm_structs.h"

int 		is_correct_file(char *file);
t_player	*get_player(char *filename);
int			is_command_code(uint8_t code);
unsigned	calc_args_size(uint8_t opcode, uint8_t enc_byte);
uint8_t		get_type_by_code(uint8_t code);
uint32_t	bytes_to_number(uint8_t *bytes, unsigned size);
unsigned	get_arg_size(uint8_t opcode, uint8_t arg_type);
int			check_filename(char *filename);

void		ft_change_extension_to_s(char **file_name);
void		put_program_name(char *name, int fd);
void		put_comment(char *comment, int fd);
void		put_commands(t_bytecode *bytecode, int fd);
int 		command_is_valid_ns(uint8_t *code, unsigned byte_idx, unsigned size);
int 		encode_byte_is_valid_ns(uint8_t opcode, uint8_t encode_byte);
unsigned	calc_command_size_ns(uint8_t opcode, uint8_t encode_byte);
void		put_command(uint8_t *code, unsigned byte_idx, int fd);
void		put_command_name(uint8_t opcode, int fd);
void		put_command_args(uint8_t *code, unsigned byte_idx,
							 				uint8_t opcode, int fd);
int 		get_fd(char *filename);
void		put_arg(uint8_t *code, unsigned size, uint8_t arg_code, int fd);
int 		check_args(int argc, char **argv);

void		disassemble(t_player *player, char *filename);

void		free_player(t_player *player);

#endif //COREWAR_DISASM_H
