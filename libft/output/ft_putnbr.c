/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:50:51 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:50:52 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int e;
	int is_negative;

	is_negative = 1;
	if (n < 0)
	{
		ft_putchar('-');
		is_negative = -1;
	}
	if (n > -10 && n < 10)
	{
		ft_putchar('0' + n * is_negative);
		return ;
	}
	e = 10;
	while ((n / e) * is_negative >= 10)
		e *= 10;
	while (e)
	{
		ft_putchar('0' + (n / e) * is_negative);
		n %= e;
		e /= 10;
	}
}
