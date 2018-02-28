/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:42:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/21 13:42:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_unsigned.h"

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

static void	add_prec_width_pref(t_spec *spec, char **res_line)
{
	if (spec->precision != -1)
		printf_process_decimal_precision(res_line, spec->precision);
	if (char_in_str('0', spec->flags) && spec->precision == -1)
	{
		printf_process_width(res_line, spec->min_width - 2, spec->flags,
					spec->precision != -1);
		add_prefix('x', res_line, "0x");
	}
	else
	{
		add_prefix('x', res_line, "0x");
		printf_process_width(res_line, spec->min_width, spec->flags,
					spec->precision != -1);
	}
}

void		printf_void(t_spec *spec, va_list ap, int *printed)
{
	void				*addr;
	unsigned long long	num;
	char				*res_line;

	addr = va_arg(ap, void *);
	num = (unsigned long long)addr;
	if (num == 0 && spec->precision == 0)
		res_line = ft_strdup("");
	else
		res_line = unsigned_itoa(num, 16);
	add_prec_width_pref(spec, &res_line);
	ft_putstr(res_line);
	*printed += ft_strlen(res_line);
	free(res_line);
}
