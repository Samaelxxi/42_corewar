/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:43:44 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:43:45 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*dstcpy;

	srccpy = (unsigned char*)src;
	dstcpy = (unsigned char*)dst;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dst);
}
