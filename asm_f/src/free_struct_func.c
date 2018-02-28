/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_struct_translate_instr(t_translate_instr **ptr)
{
	if ((*ptr)->instruction)
		free((*ptr)->instruction);
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
