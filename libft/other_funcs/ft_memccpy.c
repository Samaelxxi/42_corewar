/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:43:55 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:43:56 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char*)dst;
	srccpy = (unsigned char*)src;
	while (n--)
	{
		*dstcpy = *srccpy;
		if (*srccpy == (unsigned char)c)
			return ((void*)(dstcpy + 1));
		dstcpy++;
		srccpy++;
	}
	return (NULL);
}
