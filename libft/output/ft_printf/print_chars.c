/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:53:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/19 03:53:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_chars.h"

void		printf_string(t_spec *spec, va_list ap, int *printed)
{
	char *string;
	char *res_line;
	char *temp;

	string = va_arg(ap, char *);
	if (string == NULL)
		res_line = ft_strdup("(null)");
	else
		res_line = ft_strdup(string);
	if (spec->precision != -1 && spec->precision < (int)ft_strlen(res_line))
	{
		temp = ft_strndup(res_line, spec->precision);
		free(res_line);
		res_line = temp;
	}
	printf_process_width(&res_line, spec->min_width, spec->flags, 0);
	ft_putstr(res_line);
	*printed += ft_strlen(res_line);
	free(res_line);
}

void		print_char(t_spec *spec, int *printed, char chr)
{
	char	*res_line;

	res_line = ft_strnew(1);
	res_line[0] = chr;
	if (chr == 0)
		spec->min_width -= 1;
	printf_process_width(&res_line, spec->min_width, spec->flags, 0);
	ft_putstr(res_line);
	if (chr == '\0')
		ft_putchar('\0');
	*printed += ft_strlen(res_line) + ((chr == 0) ? 1 : 0);
	free(res_line);
}

void		printf_char(t_spec *spec, va_list ap, int *printed)
{
	char	chr;

	chr = va_arg(ap, int);
	print_char(spec, printed, chr);
}

void		printf_percent(t_spec *spec, va_list ap, int *printed)
{
	if (ap)
		print_char(spec, printed, '%');
}
