/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:48:41 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/21 12:48:42 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	digitlen(const char *str)
{
	size_t len;

	len = 0;
	while (ft_isdigit(*str++))
		len++;
	return (len);
}

int			ft_atoi(const char *str)
{
	int res;
	int is_negative;

	is_negative = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			is_negative = -1;
	if (digitlen(str) >= 19)
		if (ft_strcmp("9223372036854775807", str))
		{
			if (is_negative == 1)
				return (-1);
			else
				return (0);
		}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (int)(*str++ - '0');
	return (res * is_negative);
}
