/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:06:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/19 06:06:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static int	check_color(const char *color_name)
{
	int idx;

	idx = 0;
	while (g_colors[idx].color_str != NULL)
	{
		if (ft_strequ(g_colors[idx].color_str, color_name))
		{
			ft_putstr(g_colors[idx].color_val);
			return (1);
		}
		idx++;
	}
	return (0);
}

void		printf_process_color(const char **format, int *is_color,
									int *printed)
{
	char	*color_name;
	int		bracket_idx;

	(*format)++;
	bracket_idx = char_idx('}', (char*)*format);
	if (bracket_idx != -1)
	{
		color_name = ft_strsub(*format, 0, bracket_idx);
		if (check_color(color_name))
		{
			(*format) += bracket_idx + 1;
			if (ft_strequ(color_name, "eoc"))
				*is_color = 0;
			else
				*is_color = 1;
			free(color_name);
		}
		else
		{
			free(color_name);
			ft_putchar('{');
			*printed += 1;
		}
	}
}
