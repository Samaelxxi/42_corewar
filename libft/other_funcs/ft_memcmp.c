/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:44:19 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:44:20 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *uc1;
	unsigned char *uc2;

	if (!n)
		return (0);
	uc1 = (unsigned char*)s1;
	uc2 = (unsigned char*)s2;
	while (n && *uc1 == *uc2)
	{
		uc1++;
		uc2++;
		n--;
	}
	if (!n)
		return (0);
	return (*uc1 - *uc2);
}
