/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:56:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/24 16:56:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_unsigned.h"

void		printf_n(t_spec *spec, va_list ap, int *printed)
{
	void *ptr;

	if (spec)
	{
		ptr = va_arg(ap, void *);
		ft_memcpy(ptr, printed, 4);
	}
}

static void	process_nonpr(char *res_line, char *line, int len)
{
	int idx;
	int res_idx;

	idx = 0;
	res_idx = 0;
	while (idx < len)
	{
		if (ft_isprint(line[idx]))
			res_line[res_idx++] = line[idx++];
		else
		{
			res_line[res_idx++] = '0';
			res_line[res_idx++] = 'x';
			res_line[res_idx++] = BASE[(unsigned char)line[idx] / 16];
			res_line[res_idx++] = BASE[(unsigned char)line[idx++] % 16];
		}
	}
}

void		printf_nonpr(t_spec *spec, va_list ap, int *printed)
{
	char	*line;
	char	*res_line;
	int		non_print;
	int		idx;
	int		len;

	line = va_arg(ap, char *);
	len = (spec->precision == -1) ? ft_strlen(line) : spec->precision;
	non_print = 0;
	idx = 0;
	while (idx < len)
		if (!ft_isprint(line[idx++]))
			non_print++;
	res_line = ft_strnew(len + (non_print * 3));
	process_nonpr(res_line, line, len);
	printf_process_width(&res_line, spec->min_width, spec->flags, 0);
	ft_putstr(res_line);
	*printed += ft_strlen(res_line);
	free(res_line);
}
