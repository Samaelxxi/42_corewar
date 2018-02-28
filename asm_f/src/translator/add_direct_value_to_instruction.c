/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_direct_value_to_instruction.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_dir2_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position, t_list *dicttionary_lables)
{
	u_int16_t	dir_arg;

	if (*(argument + 1) == LABEL_CHAR)
		dir_arg = find_value_lable(inst_code, argument + 2, dicttionary_lables);
	else
		dir_arg = (uint16_t)ft_atoi(argument + 1);
	dir_arg = swap_uint16(dir_arg);
	ft_memcpy(inst_code->instruction + *free_position, &dir_arg, 2);
	*free_position = *free_position + 2;
}

void	add_dir4_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position, t_list *dicttionary_lables)
{
	u_int32_t	dir_arg;

	if (*(argument + 1) == LABEL_CHAR)
		dir_arg = find_value_lable(inst_code, argument + 2, dicttionary_lables);
	else
		dir_arg = (uint32_t)ft_atoi(argument + 1);
	dir_arg = swap_uint32(dir_arg);
	ft_memcpy(inst_code->instruction + *free_position, &dir_arg, 4);
	*free_position = *free_position + 4;
}
