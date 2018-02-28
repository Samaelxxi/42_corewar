/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:48:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/23 10:48:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	disassemble(t_player *player, char *filename)
{
	int 	fd;

	if ((fd = get_fd(filename)) == -1)
		return ;
	put_program_name(player->name, fd);
	put_comment(player->comment, fd);
	put_commands(player->bytecode, fd);
}

void	put_program_name(char *name, int fd)
{
	ft_putstr_fd(NAME_CMD_STRING, fd);
	ft_putstr_fd(" \"", fd);
	ft_putstr_fd(name, fd);
	ft_putendl_fd("\"", fd);
}

void	put_comment(char *comment, int fd)
{
	ft_putstr_fd(COMMENT_CMD_STRING, fd);
	ft_putstr_fd(" \"", fd);
	ft_putstr_fd(comment, fd);
	ft_putendl_fd("\"", fd);
}

void	put_commands(t_bytecode *bytecode, int fd)
{
	unsigned	byte_idx;

	byte_idx = 0;
	while (byte_idx < bytecode->size)
	{
		if (command_is_valid_ns(bytecode->code, byte_idx, bytecode->size))
		{
			put_command(bytecode->code, byte_idx, fd);
			byte_idx += calc_command_size_ns(bytecode->code[byte_idx], bytecode->code[byte_idx + 1]);
			continue ;
		}
		byte_idx++;
	}
}

int 	command_is_valid_ns(uint8_t *code, unsigned byte_idx, unsigned size)
{
	uint8_t 	opcode;
	uint8_t		encode_byte;
	unsigned	command_size;

	opcode = code[byte_idx];
	if (!is_command_code(opcode))
		return (0);
	if (byte_idx + 1 == size)
		return (0);
	encode_byte = code[byte_idx + 1];
	if (g_op_tab[opcode].is_encoding_byte)
		if (!encode_byte_is_valid_ns(opcode, encode_byte))
			return (0);
	command_size = calc_command_size_ns(opcode, encode_byte);
	if (byte_idx + command_size > size)
		return (0);
	return (1);
}

int 		encode_byte_is_valid_ns(uint8_t opcode, uint8_t encode_byte)
{
	unsigned	arg_idx;
	uint8_t		arg_type;

	if ((uint8_t)(encode_byte << (2 * g_op_tab[opcode].arg_num)) > 0)
		return (0);
	arg_idx = 0;
	while (arg_idx < g_op_tab[opcode].arg_num)
	{
		arg_type = get_type_by_code(get_arg_encoding(encode_byte, arg_idx));
		if (!(arg_type & g_op_tab[opcode].arg_types[arg_idx]))
			return (0);
		arg_idx++;
	}
	return (1);
}

unsigned	calc_command_size_ns(uint8_t opcode, uint8_t encode_byte)
{
	unsigned comm_size;

	comm_size = 1;
	comm_size += g_op_tab[opcode].is_encoding_byte;
	if (g_op_tab[opcode].is_encoding_byte)
		comm_size += calc_args_size(opcode, encode_byte);
	else
		comm_size += ((g_op_tab[opcode].is_index) ? 2 : 4);
	return (comm_size);
}

void	put_command(uint8_t *code, unsigned byte_idx, int fd)
{
	uint8_t		opcode;

	opcode = code[byte_idx];
	put_command_name(opcode, fd);
	put_command_args(code, byte_idx, opcode, fd);
	ft_putendl_fd("", fd);
}

void	put_command_name(uint8_t opcode, int fd)
{
	ft_putstr_fd(g_op_tab[opcode].name, fd);
	ft_putchar_fd(' ', fd);
}

void	put_command_args(uint8_t *code, unsigned byte_idx, uint8_t opcode, int fd)
{
	uint8_t		encode_byte;
	unsigned 	start;
	unsigned 	arg_idx;
	uint8_t 	arg_code;
	unsigned 	size;

	encode_byte = g_op_tab[opcode].is_encoding_byte ? code[byte_idx + 1] : (uint8_t)0x80;
	start = byte_idx + g_op_tab[opcode].is_encoding_byte + 1;
	arg_idx = 0;
	while (arg_idx < g_op_tab[opcode].arg_num)
	{
		arg_code = get_arg_encoding(encode_byte, arg_idx);
		size = get_arg_size(opcode, arg_code);
		put_arg(&code[start], size, arg_code, fd);
		if (arg_idx + 1 != g_op_tab[opcode].arg_num)
			ft_putchar_fd(SEPARATOR_CHAR, fd);
		start += size;
		arg_idx++;
	}
}

void	put_arg(uint8_t *code, unsigned size, uint8_t arg_code, int fd)
{
	if (arg_code == DIR_CODE)
	{
		ft_putchar_fd(DIRECT_CHAR, fd);
		if (size == 2)
			ft_putnbr_fd((short)bytes_to_number(code, size), fd);
		else
			ft_putnbr_fd(bytes_to_number(code, size), fd);
		return ;
	}
	if (arg_code == IND_CODE)
	{
		ft_putnbr_fd(bytes_to_number(code, size), fd);
		return ;
	}
	if (arg_code == REG_CODE)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(bytes_to_number(code, size), fd);
	}
}
