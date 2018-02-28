/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/28 18:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintarr(const int *arr, char del, size_t size)
{
	if (arr)
	{
		while (size--)
		{
			ft_putnbr(*arr++);
			if (size)
				ft_putchar(del);
		}
	}
}
