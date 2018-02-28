/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:56:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/18 14:56:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_vis.h"

void	vis_init_screen(t_vm *vm)
{
	ft_memset(vm->vis.color_field, 5, MEM_SIZE);
	vm->vis.on = 0;
	vm->vis.cps = VIS_START_CPS;
	vis_init_ncurses();
	vis_init_interface();
	vis_init_memory_field();
	vis_init_players_code(vm);
	vis_mark_processes(vm);
	vis_init_players_labels(vm);
	vis_init_vis_gui(vm);
}

void	vis_init_ncurses_colors(void)
{
	start_color();
	init_color(COLOR_GREY, 300, 300, 300);
	init_pair(DEFAULT_COLOR, COLOR_GREY, COLOR_BLACK);
	init_pair(PLAYER_1_COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(PLAYER_2_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(PLAYER_3_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(PLAYER_4_COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(DEFAULT_PROC_COLOR, COLOR_GREY, COLOR_GREY);
	init_pair(PLAYER_1_PROC, COLOR_GREY, COLOR_GREEN);
	init_pair(PLAYER_2_PROC, COLOR_GREY, COLOR_BLUE);
	init_pair(PLAYER_3_PROC, COLOR_GREY, COLOR_RED);
	init_pair(PLAYER_4_PROC, COLOR_GREY, COLOR_MAGENTA);
	init_pair(BOUND_COLOR, COLOR_GREY, COLOR_GREY);
	init_pair(LABEL_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(DEBUG_PROC_COLOR, COLOR_RED, COLOR_CYAN);
	init_pair(DEBUG_BG_COLOR, COLOR_WHITE, COLOR_WHITE);
	init_pair(DEBUG_LABEL_COLOR, COLOR_RED, COLOR_WHITE);

}

void	vis_init_ncurses(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	cbreak();
	timeout(-1);
	vis_init_ncurses_colors();
}

void	vis_init_interface(void)
{
	attron(COLOR_PAIR(BOUND_COLOR));
	mvhline(0, 0, '*', FIELD_WIDTH);
	mvhline(FIELD_HEIGHT, 0, '*', FIELD_WIDTH + 1);
	mvvline(0, FIELD_WIDTH, '*', FIELD_HEIGHT);
	mvvline(0, 0, '*', FIELD_HEIGHT);
	mvhline(0, FIELD_WIDTH, '*', GUI_WIDTH);
	mvhline(GUI_HEIGHT, FIELD_WIDTH, '*', GUI_WIDTH + 1);
	mvvline(0, FIELD_WIDTH + GUI_WIDTH, '*', GUI_HEIGHT);
	attroff(COLOR_PAIR(BOUND_COLOR));
}

void	vis_init_memory_field(void)
{
	unsigned byte_idx;

	byte_idx = 0;
	attron(COLOR_PAIR(DEFAULT_COLOR));
	while (byte_idx < MEM_SIZE)
	{
		vis_put_byte_on_screen(0, byte_idx);
		byte_idx++;
	}
	attroff(COLOR_PAIR(DEFAULT_COLOR));
}

void	vis_init_players_code(t_vm *vm)
{
	unsigned shift;
	int player_idx;
	t_list *players;
	t_player *player;
	int color;

	players = vm->players;
	player_idx = 1;
	while (player_idx <= vm->total_players)
	{
		shift = CALC_INIT_CHAMP_SHIFT(vm->total_players, (unsigned)player_idx++);
		player = lst_get_player(players);
		color = vis_get_player_color(player->player_code);
		vis_put_bytes_on_screen(color, shift, player->bytecode->code, player->bytecode->size);
		vis_mark_color_field(vm->vis.color_field, color, shift, player->bytecode->size);
		players = players->next;
	}
}

void	vis_init_vis_gui(t_vm *vm)
{
	attron(COLOR_PAIR(LABEL_COLOR));
	mvaddstr(g_label_info[PAUSE][1], GUI_LABEL_X, "** PAUSED **");
	mvaddstr(g_label_info[DELAY][1], GUI_LABEL_X, "Game speed: ");
	vis_update_delay_string(vm->vis.cps);
	mvaddstr(g_label_info[CYCLE][1], GUI_LABEL_X, "Cycle : ");
	vis_update_cycle_string(vm->current_cycle);
	mvaddstr(g_label_info[TOTAL_CYCLES][1], GUI_LABEL_X, "Total cycles : ");
	mvaddnbr(g_label_info[TOTAL_CYCLES][1], g_label_info[TOTAL_CYCLES][0], 0);
	mvaddstr(g_label_info[PROC][1], GUI_LABEL_X, "Processes : ");
	vis_update_proc_string(ft_lstlen(vm->processes));
	mvaddstr(g_label_info[MAXCHECKS][1], GUI_LABEL_X, "MAX_CHECKS : ");
	mvaddnbr(g_label_info[MAXCHECKS][1], g_label_info[MAXCHECKS][0], MAX_CHECKS);
	mvaddstr(g_label_info[NBRLIVES][1], GUI_LABEL_X, "NBR_LIVE : ");
	mvaddnbr(g_label_info[NBRLIVES][1], g_label_info[NBRLIVES][0], NBR_LIVE);
	mvaddstr(g_label_info[DELTA_C][1], GUI_LABEL_X, "CYCLE_DELTA : ");
	mvaddnbr(g_label_info[DELTA_C][1], g_label_info[DELTA_C][0], CYCLE_DELTA);
	mvaddstr(g_label_info[C_TO_DIE][1], GUI_LABEL_X, "CYCLE_TO_DIE : ");
	vis_update_c_to_die_string(vm->cycles_to_die);
	mvaddstr(g_label_info[PROC][1] + 2, GUI_LABEL_X, "Last player : ");
	vis_update_last_player_string(vm->last_player);
	attroff(COLOR_PAIR(LABEL_COLOR));
}

void	vis_print_player_name(int y, int x, t_player *player, size_t max_size)
{
	int color;
	char player_name[PROG_NAME_LENGTH + 1];

	color = vis_get_player_color(player->player_code);
	ft_memset(player_name, 0, PROG_NAME_LENGTH + 1);
	ft_strncpy(player_name, player->name, max_size);
	attron(COLOR_PAIR(color));
	mvaddstr(y, x, player_name);
	attroff(COLOR_PAIR(color));
}

void	vis_init_player_labels(t_player *player, int player_idx)
{
	int y;

	y = GUI_PLAYERS_Y + GUI_PLAYER_HEIGHT * player_idx;
	mvaddstr(y, GUI_LABEL_X, "Player ");
	mvaddnbr(y, GUI_LABEL_X + 7, player_idx + 1);
	mvaddstr(y, GUI_LABEL_X + 8, " : ");
	vis_print_player_name(y, GUI_LABEL_X + 11, player, 15);
}

void	vis_init_players_labels(t_vm *vm)
{
	int			player_idx;
	t_list		*players;
	t_player	*player;

	players = vm->players;
	player_idx = 0;
	while (players)
	{
		player = lst_get_player(players);
		vis_init_player_labels(player, player_idx);
		players = players->next;
		player_idx++;
	}
}
