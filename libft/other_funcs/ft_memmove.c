/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:44:03 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:44:04 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srccpy;
	unsigned char	*dstcpy;

	if (src > dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		srccpy = (unsigned char *)src + len - 1;
		dstcpy = (unsigned char *)dst + len - 1;
		while (len--)
			*dstcpy-- = *srccpy--;
	}
	return (dst);
}
