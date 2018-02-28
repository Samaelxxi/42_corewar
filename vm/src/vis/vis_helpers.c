/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:56:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/18 14:56:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	mvaddnbr(int y, int x, int num)
{
	char *numstr;

	numstr = ft_itoa(num);
	mvaddstr(y, x, numstr);
	free(numstr);
}

uint8_t	vis_get_player_color(uint8_t player_code[4])
{
	return (0xff - player_code[3] + 1);
}

void	vis_mark_color_field(uint8_t *field, uint8_t byte, unsigned start_idx,
							 unsigned size)
{
	unsigned byte_idx;

	byte_idx = 0;
	while (byte_idx < size)
	{
		field[(start_idx + byte_idx) % MEM_SIZE] = byte;
		byte_idx++;
	}
}

void	set_timeout(t_vm *vm)
{
	if (vm->vis.on)
		timeout(1000 / vm->vis.cps + 1);
	else
		timeout(-1);
}
