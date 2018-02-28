/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:44:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:44:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "specifier.h"
#include <stdarg.h>

intmax_t	get_int_arg(t_spec *spec, va_list ap)
{
	intmax_t num;

	num = 0;
	if (spec->len_mod == '-')
		num = va_arg(ap, int);
	else if (spec->len_mod == 'h')
		num = (short)va_arg(ap, int);
	else if (spec->len_mod == 'H')
		num = (char)va_arg(ap, int);
	else if (spec->len_mod == 'l')
		num = va_arg(ap, long);
	else if (spec->len_mod == 'K')
		num = va_arg(ap, long long);
	else if (spec->len_mod == 'j')
		num = va_arg(ap, intmax_t);
	else if (spec->len_mod == 'z')
		num = va_arg(ap, size_t);
	else
		ft_putstr("get_signed_arg error\n");
	return (num);
}

uintmax_t	get_uns_arg(t_spec *spec, va_list ap)
{
	uintmax_t num;

	num = 0;
	if (spec->len_mod == '-')
		num = va_arg(ap, unsigned int);
	else if (spec->len_mod == 'h')
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (spec->len_mod == 'H')
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (spec->len_mod == 'l')
		num = va_arg(ap, unsigned long);
	else if (spec->len_mod == 'K')
		num = va_arg(ap, unsigned long long);
	else if (spec->len_mod == 'j')
		num = va_arg(ap, uintmax_t);
	else if (spec->len_mod == 'z')
		num = va_arg(ap, size_t);
	else
		ft_putstr("get_signed_arg error\n");
	return (num);
}
