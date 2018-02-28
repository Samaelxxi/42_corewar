/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:28:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/01/28 16:28:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_whitespaces(const char *str)
{
	char	*new_str;
	int		whitespaces;
	int		idx;
	int		idx2;

	whitespaces = 0;
	idx = 0;
	while (str[idx] != '\0')
		if (ft_isspace(str[idx++]))
			whitespaces++;
	new_str = ft_strnew(ft_strlen(str) - whitespaces);
	idx = 0;
	idx2 = 0;
	while (str[idx] != '\0')
	{
		if (!ft_isspace(str[idx]))
			new_str[idx2++] = str[idx];
		idx++;
	}
	return (new_str);
}
