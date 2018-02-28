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

void			printf_parse_flags_help(char *spec_str, int spec_idx,
									char cur_flags[MAX_FLAGS_NUM], int *idx)
{
	char symb;

	symb = spec_str[spec_idx];
	if (symb == '-' && char_in_str('0', cur_flags))
		cur_flags[char_idx('0', cur_flags)] = '-';
	else if (symb == '+' && char_in_str(' ', cur_flags))
		cur_flags[char_idx(' ', cur_flags)] = '+';
	else if ((symb == ' ' && char_in_str('+', cur_flags)) ||
			(symb == '0' && char_in_str('-', cur_flags)) ||
			(symb == '0' && spec_idx > 0 &&
					ft_isdigit(spec_str[spec_idx - 1])))
		;
	else
		cur_flags[(*idx)++] = symb;
}

void			printf_parse_flags(char *spec_str, t_spec *specifier)
{
	int		idx;
	char	cur_flags[MAX_FLAGS_NUM];
	char	symb;
	int		spec_idx;

	idx = 0;
	spec_idx = 0;
	ft_memset(cur_flags, 0, MAX_FLAGS_NUM);
	while (spec_str[spec_idx] != '\0')
	{
		symb = spec_str[spec_idx];
		if (char_in_str(symb, FLAGS) && !char_in_str(symb, cur_flags))
			printf_parse_flags_help(spec_str, spec_idx, cur_flags, &idx);
		spec_idx++;
	}
	specifier->flags = ft_strsub(cur_flags, 0, idx);
}

void			printf_parse_precision(char *spec_str, t_spec *specifier,
										va_list ap)
{
	int precision;

	precision = -1;
	while (*spec_str != '\0')
	{
		if (*spec_str == '.')
		{
			spec_str++;
			if (*spec_str == '*' && *(spec_str - 1) == '.')
			{
				precision = va_arg(ap, int);
				precision = (precision < 0) ? -1 : precision;
				spec_str++;
			}
			else
			{
				precision = 0;
				while (ft_isdigit(*spec_str))
					precision = precision * 10 + (*spec_str++ - '0');
			}
		}
		else
			spec_str++;
	}
	specifier->precision = precision;
}

static char		choose_mod(char **spec_str, char mod)
{
	char temp_mod;

	if (**spec_str == 'l' && *(*spec_str + 1) == 'l')
	{
		temp_mod = 'K';
		(*spec_str)++;
	}
	else if (**spec_str == 'h' && *(*spec_str + 1) == 'h')
	{
		temp_mod = 'H';
		(*spec_str)++;
	}
	else
		temp_mod = **spec_str;
	if (char_idx(temp_mod, MODS_COMPARE) >
		char_idx(mod, MODS_COMPARE))
		mod = temp_mod;
	return (mod);
}

void			printf_parse_mods(char *spec_str, t_spec *specifier)
{
	char mod;

	while (!char_in_str(*spec_str, LEN_MODS) && *spec_str != '\0')
		spec_str++;
	if (*spec_str == '\0')
		specifier->len_mod = '-';
	else
	{
		mod = '-';
		while (*spec_str != '\0')
		{
			if (char_in_str(*spec_str, LEN_MODS))
				mod = choose_mod(&spec_str, mod);
			spec_str++;
		}
		specifier->len_mod = mod;
	}
}
