/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/17 12:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_unsigned.h"

static char	*get_prefix(char specifier)
{
	if (specifier == 'o')
		return ("0");
	else if (specifier == 'x')
		return ("0x");
	else if (specifier == 'X')
		return ("0X");
	else if (specifier == 'b')
		return ("0b");
	return ("");
}

static int	get_base(char specifier)
{
	if (specifier == 'o')
		return (8);
	else if (specifier == 'x')
		return (16);
	else if (specifier == 'X')
		return (16);
	else if (specifier == 'b')
		return (2);
	else if (specifier == 'u')
		return (10);
	write(1, "wrong spec here", 15);
	return (0);
}

static void	add_prefix(char spec, char **line, char *prefix)
{
	char *new_line;

	if (!(spec == 'o' && (*line)[0] == '0'))
	{
		new_line = ft_strnew(ft_strlen(*line) + ft_strlen(prefix));
		ft_strcpy(new_line, prefix);
		ft_strcpy(new_line + ft_strlen(prefix), *line);
		free(*line);
		*line = new_line;
	}
}

static void	add_prec_width_pref(t_spec *spec, uintmax_t num, char **res_line)
{
	char		*prefix;

	if (spec->precision != -1)
		printf_process_decimal_precision(res_line, spec->precision);
	prefix = get_prefix(spec->specifier);
	if (char_in_str('0', spec->flags) && spec->precision == -1)
	{
		if (char_in_str('#', spec->flags) && num != 0)
			spec->min_width -= ft_strlen(prefix);
		printf_process_width(res_line, spec->min_width, spec->flags,
					spec->precision != -1);
		if (char_in_str('#', spec->flags) && num != 0)
			add_prefix(spec->specifier, res_line, prefix);
	}
	else
	{
		if (char_in_str('#', spec->flags) &&
				(num != 0 || spec->specifier == 'o'))
			add_prefix(spec->specifier, res_line, prefix);
		printf_process_width(res_line, spec->min_width, spec->flags,
					spec->precision != -1);
	}
}

void		printf_unsigned(t_spec *spec, va_list ap, int *printed)
{
	uintmax_t	num;
	int			base;
	char		*res_line;

	num = get_uns_arg(spec, ap);
	base = get_base(spec->specifier);
	if (num == 0 && spec->precision == 0)
		res_line = ft_strdup("");
	else
		res_line = unsigned_itoa(num, base);
	if (spec->specifier == 'X')
		str_to_upper(res_line);
	add_prec_width_pref(spec, num, &res_line);
	ft_putstr(res_line);
	*printed += ft_strlen(res_line);
	free(res_line);
}
