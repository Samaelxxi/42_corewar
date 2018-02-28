/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:51:55 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:51:56 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int e;
	int is_negative;

	is_negative = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		is_negative = -1;
	}
	if (n > -10 && n < 10)
	{
		ft_putchar_fd('0' + n * is_negative, fd);
		return ;
	}
	e = 10;
	while ((n / e) * is_negative >= 10)
		e *= 10;
	while (e)
	{
		ft_putchar_fd('0' + (n / e) * is_negative, fd);
		n %= e;
		e /= 10;
	}
}
