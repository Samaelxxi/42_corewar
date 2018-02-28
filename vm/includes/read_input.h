/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:33:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/21 16:33:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef COREWAR_READ_INPUT_H
#define COREWAR_READ_INPUT_H

#include "vm_structs.h"

uint32_t		swap_uint32(uint32_t value);

t_player		*create_player(t_bytecode *bytecode);
t_bytecode		*read_player(char *filename);

void 			print_usage();

void 			init_numbers(t_list *players, t_list *args);
t_list			*parse_args(int argc, char **argv);
t_list 			*parse_players(t_list *args);
t_player		*get_player(char *filename);

int 			is_valid_bytecode(t_bytecode *bytecode, char *filename);
int				is_correct_magic_value(t_bytecode *bytecode, unsigned *value);
int				is_correct_header(t_bytecode *bytecode, unsigned *value);
int				is_correct_size(t_bytecode *bytecode, unsigned *value);
int				is_correct_max_size(t_bytecode *bytecode, unsigned *value);

void			magic_value_err(t_bytecode *bytecode, char *filename, unsigned value);
void			header_err(t_bytecode *bytecode, char *filename, unsigned value);
void			size_err(t_bytecode *bytecode, char *filename, unsigned value);
void			max_size_err(t_bytecode *bytecode, char *filename, unsigned size);

void			add_arg(t_list **args, char *label, char *value);

int 			check_players_numbers(t_list *args);
int 			check_options(t_list *args);
int 			check_numbers(t_list *args);
int 			check_players(t_list *args);

t_list			*get_list_from_args(char **argv);
int 			args_is_valid(t_list *args);

t_list			*get_players(t_list *args);
int 			nbr_cmp(void *a, void *b);
int 			get_player_number(t_list *args, t_list *players,
								 			unsigned player_idx);
void			init_player_number(t_player *player, int player_number,
								   			unsigned player_idx);
int 			get_number_from_args(t_list *args, unsigned player_idx);
int 			number_exists(t_list *players, int number);
int 			number_is_duplicated(t_list *args, t_arg *number);
int 			exist_dublicate_numbers(t_list *args);

void			args_deleter(void *content, size_t size);

extern			t_checking_func	g_checking_funcs[];

extern			t_option		g_options[];

//# define OPTIONS_NUMBER ((sizeof(g_options) / sizeof(t_option)) - 1)
# define OPTIONS_NUMBER 3

#endif //COREWAR_READ_INPUT_H
