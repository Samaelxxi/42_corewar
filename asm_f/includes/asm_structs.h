/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:04:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 12:04:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCTS_H
# define ASM_STRUCTS_H

#include "structs.h"

typedef struct				s_file_of_tokens
{
	char					*champ_name;
	char					*champ_desc;
	t_list					*lines;
}							t_file_of_tokens;

typedef struct				s_line_of_tokens
{
	int						line_number;
	char 					*origin_line;
	t_list					*tokens;
}							t_line_of_tokens;

typedef struct				s_token
{
	int						token_type;
	char					*token_string;
	unsigned int			start_lexem_position;
}							t_token;

typedef struct				s_parsing_error
{
	int 					error_code;
	t_token					*error_token;
}							t_parsing_error;

typedef struct				s_champion
{
	u_int8_t				*magic_value;
	u_int8_t				*size_champ;
	u_int8_t				*champ_name;
	u_int8_t				*champ_desc;
	t_bytecode				*bytecode;
}							t_champion;

typedef struct				s_champ_commands
{
	char					*champ_name;
	char					*champ_desc;
	t_list					*commands;
}							t_champ_commands;

typedef struct				s_parsed_command
{
	char					*command_str;
	uint8_t					args_type;
	char					**arg_strs;
	uint8_t					is_label;
} 							t_parsed_command;

typedef struct				s_page_dict_label
{
	char					*label_name;
	unsigned int			position;
}							t_page_dict_label;

typedef struct				s_translate_instr
{
	unsigned				size_instr;
	uint8_t					*instruction;
	unsigned				start_position_instr;
}							t_translate_instr;

/*
**  ACCESSORS
*/

t_line_of_tokens			*lst_get_line_token(t_list *lst);
void						lst_add_line_token(t_list **lst, t_line_of_tokens *line_lexem);

t_token						*lst_get_token(t_list *lst);
void						lst_add_token(t_list **lst, t_token *lexem);

t_parsed_command			*lst_get_command(t_list *lst);
void						lst_add_command(t_list **lst, t_parsed_command *command);

t_page_dict_label			*lst_get_page_dict_lable(t_list *lst);
void						lst_add_page_dict_lable(t_list **lst, t_page_dict_label *page_dict_label);

/*
**	FREE_MEMORY
*/

int 						free_all_memory(t_file_of_tokens *all_tokens, t_champion *champion,
											t_champ_commands *command);
void						free_file_of_tokens(t_file_of_tokens *all_tokens);
void						free_champion(t_champion *champion);
void						free_champ_command(t_champ_commands *command);
void						line_deleter(void	*content, size_t size);
void						token_deleter(void	*content, size_t size);
void						command_deleter(void	*content, size_t size);
void						free_dict_lables(t_list	*dictionary_lables);
void						label_deleter (void	*content, size_t size);


#endif