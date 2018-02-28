/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:47:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/21 16:47:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void magic_value_err(t_bytecode *bytecode, char *filename, unsigned value)
{
	(void)value;
	ft_printf("Error: File %s has an invalid header\n", filename);
	if (bytecode)
		free_bytecode(bytecode);
}

void header_err(t_bytecode *bytecode, char *filename, unsigned value)
{
	(void)value;
	ft_printf("Error: File %s is too small to be a champion\n", filename);
	if (bytecode)
		free_bytecode(bytecode);
}

void size_err(t_bytecode *bytecode, char *filename, unsigned value)
{
	(void)value;
	ft_printf("Error: File %s has a code size that differ from what its header says\n", filename);
	if (bytecode)
		free_bytecode(bytecode);
}

void max_size_err(t_bytecode *bytecode, char *filename, unsigned size)
{
	ft_printf("Error: File %s has too large a code (%u bytes > %u bytes)\n",
			  filename, size, CHAMP_MAX_SIZE);
	if (bytecode)
		free_bytecode(bytecode);
}
