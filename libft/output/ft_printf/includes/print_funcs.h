/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:07:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 14:07:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCS_H
# define PRINT_FUNCS_H

# include <stdarg.h>
# include "specifier.h"

# include "print_signed_decimal.h"
# include "print_unsigned.h"

void	printf_string(t_spec *spec, va_list ap, int *printed);
void	printf_wint_t(t_spec *spec, va_list ap, int *printed);
void	printf_wchar_t(t_spec *spec, va_list ap, int *printed);
void	printf_void(t_spec *spec, va_list ap, int *printed);
void	printf_unsigned(t_spec *spec, va_list ap, int *printed);
void	printf_string(t_spec *spec, va_list ap, int *printed);
void	printf_char(t_spec *spec, va_list ap, int *printed);
void	printf_percent(t_spec *spec, va_list ap, int *printed);
void	printf_n(t_spec *spec, va_list ap, int *printed);
void	printf_nonpr(t_spec *spec, va_list ap, int *printed);

void (*g_print_funcs[])(t_spec *, va_list, int *printed) =
{
	printf_signed,
	printf_unsigned,
	printf_char,
	printf_string,
	printf_wint_t,
	printf_wchar_t,
	printf_void,
	printf_percent,
	printf_n,
	printf_nonpr
};

#endif
