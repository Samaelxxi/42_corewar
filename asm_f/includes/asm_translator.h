/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_translator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:41:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/20 16:41:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TRANSLATOR_H
# define ASM_TRANSLATOR_H

#define MAX_NUM_OF_ARG 3
#define NUM_OF_INST	   16

/*
**	create_champion_code.c
*/

void		create_champion_code(t_champion *champion, t_champ_commands *parsed_commands);
u_int8_t	*translate_string_to_bytecode(char *string, size_t str_size);
uint8_t		*translate_usign_value_to_bytecode(unsigned value);
void		translate_instr_to_bytecode(t_champion *champion, t_list *dictionary_lables, t_champ_commands *parsed_commands);
void		add_instr_to_struct_bytecode(t_champion *champion, t_translate_instr *inst_code);

/*
**	create_dictionary_labels.c
*/

void		create_dictionary_labels(t_list **dictionary_lables, t_champ_commands *parsed_commands);
t_page_dict_label		*create_page_dict_label(unsigned position_lable, char *label_name);
unsigned	get_size_instruction(t_parsed_command *commands);
unsigned	get_size_arguments(u_int8_t encode_byte, int opcode);

/*
**	translate_one_instr_to_bytecode.c
*/

t_translate_instr	*translate_one_instr(t_parsed_command *command, t_list *dictionary_lables, unsigned start_position_instr);
void		put_byte_opcode_to_instruction(uint8_t *instruction, t_parsed_command *command, unsigned *free_position);
void		put_byte_coding_to_instruction(uint8_t *instruction, t_parsed_command *command, unsigned *free_position);
void		put_bytes_args_to_instruction(t_translate_instr *inst_code, t_parsed_command *command, unsigned free_position, t_list *dicttionary_lables);

/*
**	put_bytes_args_to_instruction.c
*/

void		add_reg_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position);
void		add_ind_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position, t_list *dicttionary_of_lables);
u_int16_t	find_value_lable(t_translate_instr *inst_code, char *argument, t_list *dicttionary_lables);
unsigned 	find_lable_position(char *argument, t_list *dicttionary_of_lables);

/*
**	add_direct_value_to_instruction.c.c
*/

void		add_dir2_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position, t_list *dicttionary_lables);
void		add_dir4_arg_to_instruction(t_translate_instr *inst_code, char *argument, unsigned *free_position, t_list *dicttionary_lables);




void			file_to_bytecode(t_file_of_tokens *header, t_champ_commands *parsed_cmd);
void			init_champ_commands(t_file_of_tokens *header, t_champ_commands **champ_cmd);
void			fill_champ_commands(t_list *lines, t_champ_commands *champ_cmd);
void			line_to_commands(t_line_of_tokens *line, t_champ_commands *champ_cmd);
void			create_label_cmd(t_token *token, t_list **commands);
void			create_standart_cmd(t_list *line, t_list **commands);
u_int8_t 		extract_coding_byte(t_list *line);
int 			present_coding_byte(t_token *token);
uint8_t			form_coding_byte(t_list *token);
void			fill_arg_strs(t_list *line, t_parsed_command *command);

#endif
