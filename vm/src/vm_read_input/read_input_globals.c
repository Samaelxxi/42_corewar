/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:43:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/21 16:43:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKING_FUNCS_H
# define CHECKING_FUNCS_H

# include "vm_structs.h"
# include "read_input.h"

t_checking_func	g_checking_funcs[] =
		{
				{ is_correct_header,		header_err },
				{ is_correct_magic_value,	magic_value_err },
				{ is_correct_size,			size_err },
				{ is_correct_max_size,		max_size_err },
				{ NULL,						NULL }
		};

t_option		g_options[] =
		{
				{ "-n",		1 },
				{ "-dump",	1 },
				{ "-vis",	0 },
				{ 0,		0 }
		};

#endif