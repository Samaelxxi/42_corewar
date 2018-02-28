/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:50:14 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:50:15 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return ((len == 0) ? 1 : len);
}

static int	get_left_digit(int n)
{
	if (n == -2147483648)
		return ('8');
	if (n < 0)
		n = n * -1;
	return ('0' + n % 10);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		is_negative;

	is_negative = (n < 0) ? 1 : 0;
	len = num_len(n);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (is_negative)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[len--] = get_left_digit(n);
		n /= 10;
	}
	return (res);
}
