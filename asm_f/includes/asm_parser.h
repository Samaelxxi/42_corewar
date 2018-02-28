/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:16:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/18 16:16:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSER_H
# define ASM_PARSER_H

#include "asm.h"

#define	LEXICAL_ERROR	1
#define IND_LABEL_ERROR 2
#define INSTR_ERROR		3
#define DIR_LABEL_ERROR 4
#define EXTRA_ARGS_ERR  5
#define INV_TYPE_ERR	6
#define INV_FISRT_TOKEN 7
#define NO_ARGS 		8
#define NOT_ENOUGH_ARGS 9
#define NOT_SEPARATOR	10

#define MAX_COMMS_NUM   17

/*
**	asm_parse_syntax.c
*/

int						check_syntax_error(t_line_of_tokens *line_of_tokens);
int						check_label(t_token *token, t_list *token_list, t_line_of_tokens *line);
int						check_instruction(t_token *token, t_list *token_list, t_line_of_tokens *line);
int						check_arguments(t_token *token, t_list *token_list, t_line_of_tokens *line, int opcode);
int						check_argument_cicle(t_token *token, t_list **token_list, t_line_of_tokens *line, int opcode);

/*
**	asm_parse_syntax.c
*/

int						check_value_argument(int token_type, unsigned arg_types);
void					change_value_token_type(t_token *token);
int						check_separator(t_token **token, t_list **token_list, t_line_of_tokens *line);


int						syntax_error(int nbr_line, int token_position, char *line, int err);
int						parse_all_tokens(t_file_of_tokens *header, t_champ_commands *parsed_cmds);
t_parsing_error 		*check_lexical_error(t_line_of_tokens *line_of_tokens, t_list *header);
t_parsing_error 		*check_ind_token(t_token *token, t_list *head_lines);
int						get_opcode_instr(char *token_str);
int 					search_same_label(char *name_label, t_list *point_line);
int 					search_in_line(t_list *token_pointer, char *name_label);
int 					compare_name_labels(char *name_label, char *label_string);
t_parsing_error			*check_instr_token(t_token *token);
t_parsing_error			*check_dir_token(t_token *token, t_list *head_lines);
t_parsing_error			*init_error_struct(int type_error, t_token *token);
int						print_pars_error(t_parsing_error *err, t_line_of_tokens *line_of_tokens);

#endif
