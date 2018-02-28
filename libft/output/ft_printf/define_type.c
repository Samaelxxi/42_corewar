/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:22:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 17:22:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define_type.h"

static t_type	define_type2(t_spec *spec)
{
	if (spec->specifier == '%')
		return (PERCENT_SIGN);
	else if (spec->specifier == 'n')
		return (READ_TO_N);
	else if (spec->specifier == 'r')
		return (NON_PRINT);
	else
		return (-1);
}

t_type			printf_define_type(t_spec *spec)
{
	if (spec->specifier == 'd' || spec->specifier == 'i')
		return (SIGNED);
	else if (spec->specifier == 'o' || spec->specifier == 'u' ||
				spec->specifier == 'x' || spec->specifier == 'X' ||
			spec->specifier == 'b')
		return (UNSIGNED);
	else if (spec->specifier == 'c')
	{
		if (spec->len_mod == 'l')
			return (WINT_T);
		else
			return (CHAR);
	}
	else if (spec->specifier == 's')
	{
		if (spec->len_mod == 'l')
			return (WCHAR_T_PTR);
		else
			return (CHAR_PTR);
	}
	else if (spec->specifier == 'p')
		return (VOID_PTR);
	else
		return (define_type2(spec));
}
