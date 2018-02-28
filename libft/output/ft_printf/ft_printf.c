/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:12:10 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/03 12:12:11 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		process_empty_spec(t_spec *spec, const char **format,
							const char *format_cpy)
{
	int printed;

	printed = 0;
	*format = format_cpy;
	while (char_in_str(**format, POSS_CHARS))
		(*format)++;
	if (**format == '\0')
		return (0);
	print_char(spec, &printed, (**format));
	(*format)++;
	return (printed);
}

static void		printf_spec(const char **format, va_list ap, int *printed)
{
	t_spec		*spec;
	int			func_idx;
	const char	*format_cpy;

	(*format)++;
	format_cpy = *format;
	spec = printf_process_specifier(format, ap);
	if (!spec->specifier)
		*printed += (process_empty_spec(spec, format, format_cpy));
	else
	{
		func_idx = printf_define_type(spec);
		g_print_funcs[func_idx](spec, ap, printed);
	}
	printf_free_specifier(spec);
}

static void		print_non_spec(const char **format, int *printed)
{
	char	*start;
	size_t	to_print;

	start = (char*)*format;
	to_print = 0;
	while (**format != '%' && **format != '\0')
	{
		to_print++;
		(*format)++;
	}
	write(1, start, to_print);
	*printed += to_print;
}

int				ft_printf(const char *format, ...)
{
	int		printed;
	int		is_color;
	va_list	ap;

	va_start(ap, format);
	printed = 0;
	is_color = 0;
	while (*format != '\0')
	{
		if (*format == '{')
			printf_process_color(&format, &is_color, &printed);
		else if (*format != '%')
			print_non_spec(&format, &printed);
		else
			printf_spec(&format, ap, &printed);
	}
	if (is_color)
		ft_putstr("\x1B[0m");
	va_end(ap);
	return (printed);
}
