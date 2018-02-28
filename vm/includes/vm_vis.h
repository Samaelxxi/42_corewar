/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_vis.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:52:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/18 13:52:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VIS_H
# define VM_VIS_H

# include <ncurses.h>
# include "vm.h"
# include "vm_memory_ops.h"

# define VIS_START_CPS 1000

void	set_timeout(t_vm *vm);

/*
** INITIALIZATION
*/

# define FIELD_WIDTH ((BYTES_IN_ROW) * 3 + 5)
# define FIELD_HEIGHT ((MEM_SIZE / BYTES_IN_ROW) + 3)
# define GUI_WIDTH 40
# define GUI_HEIGHT (FIELD_HEIGHT)
# define GUI_LABEL_X (FIELD_WIDTH + 3)
# define GUI_PLAYERS_Y 17
# define GUI_PLAYER_HEIGHT 4

void	vis_init_ncurses(void);
void	vis_init_interface(void);
void	vis_init_memory_field(void);
void	vis_init_players_code(t_vm *vm);
void	vis_init_vis_gui(t_vm *vm);
void	vis_init_players_labels(t_vm *vm);

/*
** SCREEN DRAWINGS ETC
*/

void	vis_mark_color_field(uint8_t *field, uint8_t byte, unsigned start_idx, unsigned size);
void	vis_put_byte_on_screen(uint8_t byte, unsigned place_idx);
void	vis_put_bytes_on_screen(int color, int start_idx, uint8_t *bytes, unsigned size);
uint8_t	vis_get_player_color(uint8_t player_code[4]);
void	vis_mark_processes(t_vm *vm);
void	vis_cycle_update(t_vm *vm);
void	vis_update_screen(t_vm *vm);
void	vis_clear_processes_on_screen(t_vm *vm);

/*
** VIS KEYS INPUT
*/

# define SPACE_KEY 32
# define PLUS_KEY 43
# define MINUS_KEY 45
# define ENTER_KEY 10
# define DEBUG_KEY 100
# define NEXT_PROC_KEY 93

# define COMM_WAIT 0
# define COMM_NO_SKIP_DRAW 2

int		vis_process_key_input(t_vm *vm);
void	vis_pause_event(t_vm *vm);
void	vis_change_delay_event(int key, t_vm *vm);

/*
** LABELS PRINTING
*/

# define LABELS_NUM 9
# define BLANK "                "

extern const int g_label_info[LABELS_NUM][2];

enum e_labels {PAUSE, DELAY, CYCLE, TOTAL_CYCLES, PROC, C_TO_DIE, DELTA_C,
	NBRLIVES, MAXCHECKS};

void	mvaddnbr(int y, int x, int num);
void	vis_update_pause_string(int vis_on);
void	vis_update_delay_string(int delay);
void	vis_update_cycle_string(int cycles);
void	vis_update_proc_string(int procs);
void	vis_update_c_to_die_string(int procs);
void	vis_update_last_player_string(t_player *last_player);
void	vis_print_player_name(int y, int x, t_player *player, size_t max_size);

/*
** DEBUGGER MODE
*/

# define DEBUG_LY 35
# define DEBUG_LX ((FIELD_WIDTH) + 2)
# define DEBUG_HEIGHT 19
# define DEBUG_WIDTH 37

void	vis_debug_init_gui(void);
void	vis_debug_draw_proc_data(t_process *proc, t_vm *vm);
void	vis_clear_debug_gui(void);
void	vis_process_debug_mode(t_vm *vm);
void	vis_switch_debug_mode(t_vm *vm);
void	debug_clear_process_caret(t_vm *vm);
void	vis_debug_draw_reg(int y, int x, uint8_t reg[REG_SIZE]);
void	vis_debug_draw_byte(int y, int x, uint8_t byte);
void	vis_debug_reset_gui(t_vm *vm);
void	vis_debug_print_proc_info(t_process *proc);
void	vis_debug_draw_proc_caret(t_vm *vm);
void	vis_debug_print_player_name(t_process *proc);
void	vis_debug_print_process_instr(t_process *proc);
void	vis_debug_print_proc_reg_values(t_process *proc);
void	vis_debug_init_draw_regs(void);
void	vis_debug_init_draw_labels(void);
void	vis_debug_switch_proc(t_vm *vm);

/*
** COLORS
*/

# define COLOR_GREY 10
# define PLAYER_1_COLOR 1
# define PLAYER_2_COLOR 2
# define PLAYER_3_COLOR 3
# define PLAYER_4_COLOR 4
# define DEFAULT_COLOR 5
# define PROC_COLOR_SHIFT 100
# define PLAYER_1_PROC 101
# define PLAYER_2_PROC 102
# define PLAYER_3_PROC 103
# define PLAYER_4_PROC 104
# define DEFAULT_PROC_COLOR 105
# define LABEL_COLOR 7
# define BOUND_COLOR 8
# define DEBUG_PROC_COLOR 12
# define DEBUG_BG_COLOR 13
# define DEBUG_LABEL_COLOR 14

#endif
