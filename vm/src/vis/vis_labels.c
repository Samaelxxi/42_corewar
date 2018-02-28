/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_labels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:52:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/19 10:52:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_update_pause_string(int vis_on)
{
	if (vis_on == 0)
	{
		attron(COLOR_PAIR(LABEL_COLOR));
		mvaddstr(g_label_info[PAUSE][1], GUI_LABEL_X, "** PAUSED **");
		attroff(COLOR_PAIR(LABEL_COLOR));
	}
	else
		mvaddstr(g_label_info[PAUSE][1], GUI_LABEL_X, BLANK);
}

void	vis_update_delay_string(int delay)
{
	mvaddstr(g_label_info[DELAY][1], g_label_info[DELAY][0], BLANK);
	mvaddnbr(g_label_info[DELAY][1], g_label_info[DELAY][0], delay);
}

void	vis_update_cycle_string(int cycles)
{
	mvaddstr(g_label_info[CYCLE][1], g_label_info[CYCLE][0], BLANK);
	mvaddnbr(g_label_info[CYCLE][1], g_label_info[CYCLE][0], cycles);
}

void	vis_update_proc_string(int procs)
{
	mvaddstr(g_label_info[PROC][1], g_label_info[PROC][0], BLANK);
	mvaddnbr(g_label_info[PROC][1], g_label_info[PROC][0], procs);
}

void	vis_update_c_to_die_string(int procs)
{
	mvaddstr(g_label_info[C_TO_DIE][1], g_label_info[C_TO_DIE][0], BLANK);
	mvaddnbr(g_label_info[C_TO_DIE][1], g_label_info[C_TO_DIE][0], procs);
}

void	vis_update_last_player_string(t_player *last_player)
{
	mvaddstr(g_label_info[PROC][1] + 2, GUI_LABEL_X + 15, BLANK);
	vis_print_player_name(g_label_info[PROC][1] + 2, GUI_LABEL_X + 15, last_player, 15);
}
