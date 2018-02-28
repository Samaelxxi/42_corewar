/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:36:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/21 09:36:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	define_num_of_bytes(wint_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else
		return (4);
}

int			ft_wcrtomb(char *buf, wint_t wchar)
{
	int		total_bytes;
	int		byte_idx;
	char	byte;

	total_bytes = define_num_of_bytes(wchar);
	if (total_bytes == 1)
	{
		buf[0] = (unsigned char)wchar;
		return (1);
	}
	byte_idx = total_bytes - 1;
	while (byte_idx > 0)
	{
		byte = 128 + (wchar & 0x3F);
		buf[byte_idx--] = byte;
		wchar >>= 6;
	}
	byte = (255 >> (8 - total_bytes)) << (8 - total_bytes);
	byte += wchar;
	buf[0] = byte;
	return (total_bytes);
}
