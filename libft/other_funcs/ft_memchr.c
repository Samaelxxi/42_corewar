/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:44:10 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:44:11 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrcpy;
	unsigned char	byte;

	ptrcpy = (unsigned char*)s;
	byte = (unsigned char)c;
	while (n--)
	{
		if (*ptrcpy == byte)
			return ((void*)ptrcpy);
		ptrcpy++;
	}
	return (NULL);
}
