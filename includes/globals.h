/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:03:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:03:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

#include <stdint.h>

# define INST_SIZE				1
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_ARG_SIZE 1
# define IND_ARG_SIZE 2

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

/*
**
*/

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
**
*/

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define REG_NUMBER				16

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define MAX_COMMS_NUMBER 17

# define MAGIC_VALUE_SIZE 4
# define PADDING_AFTER_PROG_NAME_SIZE 4
# define CODE_SIZE 4
# define PADDING_AFTER_COMMENT_SIZE 4

extern const unsigned		g_header_size;

typedef struct				s_operation
{
	char			*name;
	unsigned		arg_num;
	unsigned		arg_types[MAX_ARGS_NUMBER];
	uint8_t			opcode;
	unsigned		cycles;
	char			*description;
	unsigned		is_encoding_byte;
	unsigned		is_index;
}							t_operation;

extern const t_operation	g_op_tab[17];
extern const unsigned		g_dir_arg_size[17];

/*
**	asm_parse_syntax.c
*/

uint8_t		get_arg_encoding(uint8_t enc_byte, unsigned arg_idx);
uint32_t	swap_uint32(uint32_t value);
uint16_t	swap_uint16(uint16_t value);

#endif
