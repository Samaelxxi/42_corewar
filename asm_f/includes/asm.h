/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:59:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 15:59:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "globals.h"
#include "asm_globals.h"
#include "asm_structs.h"
#include "asm_lexer.h"
#include "asm_parser.h"
#include "asm_translator.h"

#define MIN_TOKEN_VALUE 20
#define START 			21
#define LABEL_PRES		1
#define LABEL_NOT_PRES  2

#define TOKEN_ERROR 	22
#define TOKEN_IND 		23
#define TOKEN_INSTR		24
#define TOKEN_SEPARATOR	25
#define TOKEN_REG 		26
#define TOKEN_LABEL 	27
#define TOKEN_DIR 		28

/*
**	asm_main.c
*/

void						write_champ_to_file(int fd, t_champion *champion);

/*
**	free_struct_func.c
*/

void	free_struct_translate_instr(t_translate_instr **ptr);

/*
**	operation_with_file.c
*/

int							open_file(int argc, char **argv);
int							create_newfile(char *file_name);
int							check_file_name(char*file_name);
void						ft_change_extension_to_cor(char **file_name);

#endif
