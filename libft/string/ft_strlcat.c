/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:11:43 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/25 18:11:45 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*dest_end;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (size < len)
		len = size;
	len += ft_strlen(src);
	if (size)
	{
		dest_end = dst;
		while (*dest_end++ != '\0')
			i++;
		dest_end--;
		while (*src != '\0' && i++ < size - 1)
			*dest_end++ = *src++;
		*dest_end = '\0';
	}
	return (len);
}
