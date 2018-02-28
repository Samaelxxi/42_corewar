/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:44:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 12:44:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

static void	replace_big_spec(t_spec *specifier)
{
	if (specifier->specifier == 'S')
	{
		specifier->len_mod = 'l';
		specifier->specifier = 's';
	}
	else if (specifier->specifier == 'D')
	{
		specifier->len_mod = 'l';
		specifier->specifier = 'd';
	}
	else if (specifier->specifier == 'O')
	{
		specifier->len_mod = 'l';
		specifier->specifier = 'o';
	}
	else if (specifier->specifier == 'U')
	{
		specifier->len_mod = 'l';
		specifier->specifier = 'u';
	}
	else if (specifier->specifier == 'C')
	{
		specifier->len_mod = 'l';
		specifier->specifier = 'c';
	}
}

static int	get_spec_str(const char *format, char **spec_str)
{
	int offset;

	offset = 0;
	while (!(char_in_str(format[offset], SPECIFIERS)) &&
			format[offset] != '\0')
		offset++;
	*spec_str = ft_strsub(format, 0, offset + 1);
	return (offset);
}

t_spec		*printf_process_specifier(const char **format, va_list ap)
{
	t_spec	*specifier;
	char	*spec_str;
	int		offset;

	specifier = malloc(sizeof(t_spec));
	offset = get_spec_str(*format, &spec_str);
	(*format) += offset + 1;
	printf_parse_flags(spec_str, specifier);
	printf_parse_width(spec_str, specifier, ap);
	printf_parse_precision(spec_str, specifier, ap);
	printf_parse_mods(spec_str, specifier);
	printf_parse_specifier(spec_str, specifier);
	free(spec_str);
	replace_big_spec(specifier);
	return (specifier);
}

void		printf_free_specifier(t_spec *spec)
{
	free(spec->flags);
	free(spec);
}
