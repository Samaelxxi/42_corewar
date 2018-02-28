/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:06:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/17 10:06:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_TYPE_H
# define DEFINE_TYPE_H

# include "specifier.h"

typedef enum	e_print_type
{
	SIGNED,
	UNSIGNED,
	CHAR,
	CHAR_PTR,
	WINT_T,
	WCHAR_T_PTR,
	VOID_PTR,
	PERCENT_SIGN,
	READ_TO_N,
	NON_PRINT
}				t_type;

t_type			printf_define_type(t_spec *spec);

#endif
