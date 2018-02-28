/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:40:44 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/25 10:40:45 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	idx;

	idx = 0;
	while (src[idx] != '\0' && idx < len)
	{
		dst[idx] = src[idx];
		idx++;
	}
	while (idx < len)
	{
		dst[idx] = '\0';
		idx++;
	}
	return (dst);
}
