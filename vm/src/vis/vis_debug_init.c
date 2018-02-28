/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_debug_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:09:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/26 16:09:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_debug_init_gui(void)
{
	attron(COLOR_PAIR(DEBUG_BG_COLOR));
	vis_clear_debug_gui();
	attroff(COLOR_PAIR(DEBUG_BG_COLOR));
	attron(COLOR_PAIR(DEBUG_LABEL_COLOR));
	vis_debug_init_draw_labels();
	vis_debug_init_draw_regs();
	attroff(COLOR_PAIR(DEBUG_LABEL_COLOR));
}

void	vis_debug_init_draw_regs(void)
{
	int		reg_num;

	reg_num = 0;
	while (reg_num < REG_NUMBER)
	{
		mvaddstr(DEBUG_LY + 10 + reg_num / 2,    // interface magic
				 DEBUG_LX + 1 + reg_num % 2 * 17 + reg_num % 2,
				 "|r  |");
		mvaddnbr(DEBUG_LY + 10 + reg_num / 2,
				 DEBUG_LX + 1 + reg_num % 2 * 17 + 2 + reg_num % 2,
				 reg_num + 1);
		reg_num++;
	}
}

void	vis_debug_init_draw_labels(void)
{
	mvaddstr(DEBUG_LY + 1, DEBUG_LX + 14, "DEBUGGER");
	mvaddstr(DEBUG_LY + 3, DEBUG_LX + 2, "PROCESS PLAYER: ");
	mvaddstr(DEBUG_LY + 5, DEBUG_LX + 2,  "PROCESS INSTRUCTION: ");
	mvaddstr(DEBUG_LY + 6, DEBUG_LX + 2,  "INSTRUCTION CYCLES: ");
	mvaddstr(DEBUG_LY + 7, DEBUG_LX + 2,  "CARRY: ");
	mvaddstr(DEBUG_LY + 9, DEBUG_LX + 9, "PROCESS REGISTERS");
}
