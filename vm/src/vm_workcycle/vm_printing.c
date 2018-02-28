/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:44:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 15:44:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_player(t_player *player)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			  player->player_num, player->bytecode->size,
			  player->name, player->comment);
}

void		print_introduction(t_vm *vm)
{
	t_list *players;

	ft_printf("Introducing contestants...\n");
	players = vm->players;
	while (players)
	{
		print_player(lst_get_player(players));
		players = players->next;
	}
}

void		print_byte_row(uint8_t *field, int field_idx)
{
	int cur_byte_idx;

	cur_byte_idx = 0;
	while (cur_byte_idx < BYTES_IN_ROW)
	{
		ft_printf("%.2x ", field[field_idx]);
		cur_byte_idx++;
		field_idx++;
	}
}

void		print_memory_field(uint8_t *field)
{
	int byte_idx;

	byte_idx = 0;
	while (byte_idx < MEM_SIZE)
	{
		ft_printf("0x%.4x : ", byte_idx);
		print_byte_row(field, byte_idx);
		ft_printf("\n");
		byte_idx += 64;
	}
}
