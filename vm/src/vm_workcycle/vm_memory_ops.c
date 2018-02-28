/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_memory_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:01:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 18:01:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		write_bytes_on_field(uint8_t *byte_field, unsigned write_idx,
								const uint8_t *bytes, unsigned size)
{
	uint32_t byte_idx;

	byte_idx = 0;
	while (size--)
	{
		write_idx = write_idx % MEM_SIZE;
		byte_field[write_idx] = bytes[byte_idx];
		write_idx++;
		byte_idx++;
	}
}

void		write_bytecode_on_field(t_vm *vm, unsigned write_idx, t_bytecode *bytecode)
{
	write_bytes_on_field(vm->byte_field, write_idx, bytecode->code, bytecode->size);
}

void		clear_write_bytes_lst(t_vm *vm)
{
	if (vm->bytes_to_write)
		ft_lstdel(&(vm->bytes_to_write), double_deleter);
}

uint8_t		get_byte_from_field(uint8_t byte_field[MEM_SIZE], uint32_t byte_idx)
{
	byte_idx %= MEM_SIZE;
	return (byte_field[byte_idx]);
}

void		read_bytes_from_field(uint8_t *bytes, uint32_t start,
								  uint32_t size, uint8_t byte_field[MEM_SIZE])
{
	uint32_t	byte_idx;

	byte_idx = 0;
	while (size--)
		bytes[byte_idx++] = get_byte_from_field(byte_field, start++);
}