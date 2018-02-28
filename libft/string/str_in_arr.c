/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_in_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:06:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/07 14:06:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_in_arr(const char *str, const char **arr)
{
	int idx;

	idx = 0;
	if (arr)
	{
		while (arr[idx] != NULL)
		{
			if (ft_strequ(str, arr[idx]))
				return (idx);
			idx++;
		}
	}
	return (-1);
}
