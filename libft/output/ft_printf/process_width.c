/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:25:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:25:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_funcs.h"

void		printf_process_width(char **line, int width, char *flags, int prec)
{
	char	*new_line;
	char	pad_symb;
	int		line_len;
	int		idx;

	line_len = ft_strlen(*line);
	if (line_len >= width)
		return ;
	pad_symb = (char_in_str('0', flags) && !prec) ? '0' : ' ';
	new_line = ft_strnew(width);
	idx = (char_in_str('-', flags)) ? ft_strlen(*line) : 0;
	if (char_in_str('-', flags))
	{
		ft_strcpy(new_line, *line);
		while (idx < width)
			new_line[idx++] = pad_symb;
	}
	else
	{
		while (idx < width - line_len)
			new_line[idx++] = pad_symb;
		ft_strcpy(new_line + idx, *line);
	}
	free(*line);
	*line = new_line;
}
