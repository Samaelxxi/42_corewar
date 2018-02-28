/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:18:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:18:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_signed_decimal.h"

static int	get_prefix(intmax_t num, char *flags)
{
	if (num < 0 || char_in_str(' ', flags) || char_in_str('+', flags))
	{
		if (num < 0)
			return ('-');
		else if (char_in_str(' ', flags))
			return (' ');
		else
			return ('+');
	}
	return (0);
}

static void	add_prefix(char **line, char prefix)
{
	char *new_line;

	if (prefix)
	{
		new_line = ft_strnew(ft_strlen(*line) + 1);
		new_line[0] = prefix;
		ft_strcpy(new_line + 1, *line);
		free(*line);
		*line = new_line;
	}
}

static void	add_prec_width_pref(t_spec *spec,
								char **res_line, char prefix)
{
	if (spec->precision != -1)
		printf_process_decimal_precision(res_line, spec->precision);
	if (char_in_str('0', spec->flags) && spec->precision == -1)
	{
		if (prefix)
			spec->min_width -= 1;
		printf_process_width(res_line, spec->min_width, spec->flags,
					spec->precision != -1);
		add_prefix(res_line, prefix);
	}
	else
	{
		add_prefix(res_line, prefix);
		printf_process_width(res_line, spec->min_width, spec->flags,
					spec->precision != -1);
	}
}

void		printf_signed(t_spec *spec, va_list ap, int *printed)
{
	intmax_t	num;
	char		*res_line;
	char		prefix;

	num = get_int_arg(spec, ap);
	prefix = get_prefix(num, spec->flags);
	if (num == 0 && spec->precision == 0)
		res_line = ft_strdup("");
	else
		res_line = signed_itoa(num);
	add_prec_width_pref(spec, &res_line, prefix);
	ft_putstr(res_line);
	*printed += ft_strlen(res_line);
	free(res_line);
}
