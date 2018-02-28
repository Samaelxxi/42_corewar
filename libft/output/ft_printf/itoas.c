/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:21:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/19 03:21:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_unsigned.h"

static int	snum_len_in_chars(intmax_t num, int base)
{
	int len;

	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

static int	unum_len_in_chars(uintmax_t num, int base)
{
	int len;

	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char		*unsigned_itoa(uintmax_t num, int base)
{
	int		len;
	char	*str;

	len = unum_len_in_chars(num, base);
	str = ft_strnew(len);
	len--;
	if (!num)
		str[len--] = '0';
	while (num)
	{
		str[len] = BASE[num % base];
		num /= base;
		len--;
	}
	return (str);
}

char		*signed_itoa(intmax_t num)
{
	int		len;
	char	*str;
	int		is_neg;

	len = snum_len_in_chars(num, 10);
	is_neg = (num < 0) ? -1 : 1;
	str = ft_strnew(len);
	len--;
	if (!num)
		str[len--] = '0';
	while (num)
	{
		str[len] = '0' + (num % (10 * is_neg)) * is_neg;
		num /= 10;
		len--;
	}
	return (str);
}
