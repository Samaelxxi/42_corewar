/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_globals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:04:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 12:04:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_globals.h"

const int g_table[18][10] =
{//             whitespace    %            -            ,            \0 || #      :            letter       digit        letter(r)    other
/* 0 */			{START,       9,           8,           3,    	 	 TOKEN_ERROR, 14, 		   6, 	        17, 		 4, 		  TOKEN_ERROR},
/* 1 */			{TOKEN_IND,   TOKEN_IND,   TOKEN_IND,   TOKEN_IND,	 TOKEN_IND,   TOKEN_IND,   TOKEN_IND,   1,   		 TOKEN_IND,   TOKEN_ERROR},
/* 2 */			{TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, 7, 		   2, 		    2, 			 2, 		  TOKEN_ERROR},
/* 3 */			{TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR,  TOKEN_SEPARATOR},
/* 4 */			{TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_LABEL, 6, 		    5, 			 6, 		  TOKEN_ERROR},
/* 5 */			{TOKEN_REG,   TOKEN_REG,   TOKEN_REG,   TOKEN_REG, 	 TOKEN_REG,   7, 		   6, 		    15, 		 6, 		  TOKEN_ERROR},
/* 6 */			{TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, TOKEN_INSTR, 7, 		   6, 		    6, 			 6, 		  TOKEN_ERROR},
/* 7 */			{TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL, TOKEN_LABEL},
/* 8 */			{TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, 1, 			 TOKEN_ERROR, TOKEN_ERROR},
/* 9 */			{TOKEN_ERROR, TOKEN_ERROR, 10,          TOKEN_ERROR, TOKEN_ERROR, 12, 		   TOKEN_ERROR, 11, 		 TOKEN_ERROR, TOKEN_ERROR},
/* 10 */		{TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, 11, 		 TOKEN_ERROR, TOKEN_ERROR},
/* 11 */		{TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   11, 		 TOKEN_DIR,   TOKEN_ERROR},
/* 12 */		{TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, 13, 		    13, 		 13, 		  TOKEN_ERROR},
/* 13 */		{TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR,   TOKEN_DIR, 	 TOKEN_DIR,   TOKEN_DIR,   13, 		    13, 		 13, 		  TOKEN_ERROR},
/* 14 */		{TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, TOKEN_ERROR, 16, 		    16, 		 16, 		  TOKEN_ERROR},
/* 15 */		{TOKEN_REG,   TOKEN_REG,   TOKEN_REG, 	TOKEN_REG, 	 TOKEN_REG,   7, 		   6, 		    6, 			 6, 		  TOKEN_ERROR},
/* 16 */		{TOKEN_IND,   TOKEN_IND,   TOKEN_IND, 	TOKEN_IND,   TOKEN_IND,   TOKEN_IND,   16, 		    16, 		 16, 		  TOKEN_ERROR},
/* 17 */		{TOKEN_IND,   TOKEN_IND,   TOKEN_IND, 	TOKEN_IND,   TOKEN_IND,   7, 		   2, 		    17, 		 2, 		  TOKEN_ERROR}
};

