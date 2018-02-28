/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_globals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:54:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 11:54:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_globals.h"
#include "vm_process_execution.h"

const uint8_t g_player_colors[MAX_PLAYERS] =
{
	COLOR_GREEN, COLOR_BLUE,
	COLOR_RED, COLOR_MAGENTA
};

const t_comm_func g_comm_funcs[17] =
{
	NULL,
	live_comm,
	ld_comm,
	st_comm,
	add_comm,
	sub_comm,
	and_comm,
	or_comm,
	xor_comm,
	zjmp_comm,
	ldi_comm,
	sti_comm,
	fork_comm,
	lld_comm,
	lldi_comm,
	lfork_comm,
	aff_comm
};

const int g_label_info[LABELS_NUM][2] =
{
	{GUI_LABEL_X, 2},
	{GUI_LABEL_X + 13, 4},
	{GUI_LABEL_X + 8, 7},
	{GUI_LABEL_X + 15, 9},
	{GUI_LABEL_X + 12, 11},
	{GUI_LABEL_X + 15, FIELD_HEIGHT - 2},
	{GUI_LABEL_X + 14, FIELD_HEIGHT - 4},
	{GUI_LABEL_X + 11, FIELD_HEIGHT - 6},
	{GUI_LABEL_X + 13, FIELD_HEIGHT - 8}
};
