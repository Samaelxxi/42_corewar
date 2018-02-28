/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_globals.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 11:52:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_GLOBALS_H
# define VM_GLOBALS_H

# include "globals.h"
#include "vm_structs.h"
# include "vm_vis.h"

/*
** VM
*/

# define CALC_INIT_CHAMP_SHIFT(all, num) (MEM_SIZE / (all) * ((num) - 1))

# define NO_MODE 0
# define DUMP_MODE 1
# define VIS_MODE 2

# define BYTES_IN_ROW 64
# define COMMANDS_QUANTITY 16

# define NOT_MODIFY_CARRY (-1)

extern const uint8_t g_default_player_code[4];

typedef int (*t_comm_func)(t_process *proc, t_vm *vm);

extern const t_comm_func g_comm_funcs[17];

extern const uint8_t		g_player_colors[MAX_PLAYERS];

#endif
