/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:51:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 11:51:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

#include "libft.h"
#include "structs.h"

typedef struct	s_arg
{
	char		*flag;
	char		*value;
}				t_arg;

typedef struct	s_input_data
{
	t_list		*args;
	t_list		*players;
}				t_input_data;

typedef struct	s_proc_command
{
	uint8_t opcode;
	uint32_t exec_counter;
	uint8_t encode_byte;
	uint8_t args[3][4];
}				t_proc_command;

typedef struct	s_process
{
	uint32_t pc;
	uint8_t registers[REG_NUMBER + 1][REG_SIZE];
	int carry;
	uint8_t player_code[4];
	unsigned lives;
	t_proc_command comm;
}				t_process;

typedef struct	s_player
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	uint8_t		player_code[4];
	t_bytecode	*bytecode;
	int			player_num;
}				t_player;

typedef struct	s_vm_mode
{
	int mode;
	int arg;
}				t_vm_mode;

typedef struct	s_vis_data
{
	uint8_t color_field[MEM_SIZE];
	int			cps;
	int			on;
	int			debug_on;
	t_process	*debug_proc;
	unsigned	proc_prev_pc;
}				t_vis_data;

typedef struct	s_vm
{
	uint8_t byte_field[MEM_SIZE];
	t_list		*bytes_to_write;
	unsigned noeffect_checks;
	unsigned long total_cycles;
	unsigned current_cycle;
	unsigned cycles_to_die;
	int total_players;
	t_list *players;
	t_list *processes;
	t_player *last_player;
	t_vm_mode vm_mode;
	t_vis_data vis;
}				t_vm;

typedef struct	s_bytes_to_write
{
	uint8_t bytes[REG_SIZE];
	unsigned size;
	unsigned idx;
	t_player *player;
}				t_bytes_to_write;


typedef struct	s_checking_func
{
	int 		(*checking_func)(t_bytecode *bytecode, unsigned *value);
	void		(*error_handler)(t_bytecode *bytecode, char *text, unsigned value);
}				t_checking_func;

typedef struct 	s_option
{
	char 	*label;
	uint8_t	value;
}				t_option;

/*
**  ACCESSORS
*/

t_arg			*lst_get_arg(t_list *lst);
void			lst_add_arg(t_list **lst, t_arg *arg);

t_player		*lst_get_player(t_list *lst);
void			lst_add_player(t_list **lst, t_player *player);

t_bytes_to_write	*lst_get_write_bytes(t_list *lst);
void				lst_add_write_bytes(t_list **lst, t_bytes_to_write *bytes);

t_process		*lst_get_process(t_list *lst);
void			lst_add_process(t_list **lst, t_process *process);
void			lst_append_process(t_list **lst, t_process *process);

void		free_args(t_list **args);
void 		free_bytecode(t_bytecode *bytecode);
void		free_players(t_list **players);
void		process_deleter(void *content, size_t size);

#endif
