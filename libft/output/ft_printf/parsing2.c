/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:47:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 13:47:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

static void		add_flag(char **flags)
{
	int		l;
	char	*new_flags;

	l = ft_strlen(*flags);
	new_flags = ft_strnew(l + 1);
	ft_strncpy(new_flags, *flags, MAX_FLAGS_NUM);
	free(*flags);
	new_flags[l] = '-';
	*flags = new_flags;
}

static int		dot_before(char *spec_str, char *start)
{
	while (ft_isdigit(*spec_str) && spec_str != start)
		spec_str--;
	return (*spec_str == '.');
}

static void		parse_width2(char *spec_str, t_spec *specifier,
								int *width, va_list ap)
{
	char	*start;

	start = spec_str;
	if (((ft_isdigit(*spec_str)) && !dot_before(spec_str, start))
		&& *spec_str != '0')
	{
		*width = 0;
		while (ft_isdigit(*spec_str))
			*width = *width * 10 + (*spec_str++ - '0');
		spec_str--;
	}
	else if (*spec_str == '*' &&
			!(spec_str != start && *(spec_str - 1) == '.'))
	{
		*width = va_arg(ap, int);
		if (*width < 0)
		{
			*width = -*width;
			add_flag(&specifier->flags);
		}
	}
}

void			printf_parse_width(char *spec_str, t_spec *specifier,
									va_list ap)
{
	int		width;

	width = 0;
	while (*spec_str != '\0')
	{
		parse_width2(spec_str, specifier, &width, ap);
		spec_str++;
	}
	specifier->min_width = width;
}

void			printf_parse_specifier(char *spec_str,
										t_spec *specifier)
{
	while (!char_in_str(*spec_str, SPECIFIERS)
			&& char_in_str(*spec_str, POSS_CHARS)
			&& *spec_str != '\0')
		spec_str++;
	if (char_in_str(*spec_str, SPECIFIERS))
		specifier->specifier = *spec_str;
	else
		specifier->specifier = 0;
}
