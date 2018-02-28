/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:51:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 13:51:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include <stdarg.h>
#include <wchar.h>
#include "general_funcs.h"

void		printf_wint_t(t_spec *spec, va_list ap, int *printed)
{
	wint_t			wchar;
	char			buf[7];
	char			*res_line;
	int				bytes;

	ft_memset(buf, 0, 7);
	wchar = va_arg(ap, wint_t);
	if (wchar == 0)
		spec->min_width -= 1;
	bytes = ft_wcrtomb(buf, wchar);
	res_line = ft_strnew(bytes);
	res_line = ft_strncpy(res_line, buf, bytes);
	printf_process_width(&res_line, spec->min_width, spec->flags, 0);
	ft_putstr(res_line);
	if (wchar == 0)
		ft_putchar('\0');
	*printed += ft_strlen(res_line) + ((wchar == 0) ? 1 : 0);
	free(res_line);
}

static void	translate_wstr_to_mb(char **res_line, wchar_t *wstr,
									t_spec *spec)
{
	char	buf[7];
	wint_t	wchar;
	char	*temp;
	int		written;

	*res_line = ft_strnew(1);
	wchar = *wstr++;
	written = 0;
	while (wchar)
	{
		ft_memset(buf, 0, 7);
		written += ft_wcrtomb(buf, wchar);
		if (spec->precision != -1 && spec->precision < written)
			break ;
		temp = ft_strjoin(*res_line, buf);
		free(*res_line);
		*res_line = temp;
		wchar = *wstr++;
	}
}

void		printf_wchar_t(t_spec *spec, va_list ap, int *printed)
{
	wchar_t	*wstr;
	char	*res_line;
	char	*temp;

	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL)
		res_line = ft_strdup("(null)");
	else
		translate_wstr_to_mb(&res_line, wstr, spec);
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
