/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:41:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:41:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_funcs.h"

void		printf_process_decimal_precision(char **line, int precision)
{
	int		idx;
	int		len;
	char	prefix;
	char	*new_line;

	idx = 0;
	prefix = 0;
	len = 0;
	if ((*line)[0] == '-' || (*line)[0] == '+' || (*line)[0] == ' ')
		prefix = (*line)[idx++];
	while ((*line)[idx++] != '\0')
		len++;
	if (precision > len)
	{
		new_line = ft_strnew(precision + ((prefix) ? 1 : 0) + 1);
		idx = 0;
		if (prefix)
			new_line[idx++] = prefix;
		while (precision-- > len)
			new_line[idx++] = '0';
		ft_strcpy(new_line + idx, (*line) + ((prefix) ? 1 : 0));
		free(*line);
		*line = new_line;
	}
}
