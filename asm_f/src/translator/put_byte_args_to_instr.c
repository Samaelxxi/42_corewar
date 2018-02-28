/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bytes_args_to_instruction.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_reg_arg_to_instruction(t_translate_instr *inst_code,
								char *argument, unsigned *free_position)
{
	uint8_t		reg;

	reg = (uint8_t)ft_atoi(argument + 1);
	inst_code->instruction[*free_position] = reg;
	*free_position += 1;
}

void		add_ind_arg_to_instruction(t_translate_instr *inst_code,
		char *argument, unsigned *free_position, t_list *dicttionary_of_lables)
{
	u_int16_t	ind_arg;

	if (*argument == LABEL_CHAR)
		ind_arg = find_value_lable(inst_code, argument + 1,
										dicttionary_of_lables);
	else
		ind_arg = (uint16_t)ft_atoi(argument);
	ind_arg = swap_uint16(ind_arg);
	ft_memcpy(inst_code->instruction + *free_position, &ind_arg, 2);
	*free_position += 2;
}

u_int16_t	find_value_lable(t_translate_instr *inst_code, char *argument,
												t_list *dicttionary_lables)
{
	unsigned	label_position;

	label_position = find_lable_position(argument, dicttionary_lables);
	return ((u_int16_t)(label_position - inst_code->start_position_instr));
}

unsigned	find_lable_position(char *argument, t_list *dicttionary_of_lables)
{
	t_page_dict_label	*lable_page;

	while (dicttionary_of_lables)
	{
		lable_page = lst_get_page_dict_lable(dicttionary_of_lables);
		if (!ft_strcmp(lable_page->label_name, argument))
			break ;
		dicttionary_of_lables = dicttionary_of_lables->next;
	}
	return (lable_page->position);
}
