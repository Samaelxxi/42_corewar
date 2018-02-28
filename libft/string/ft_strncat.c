/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:45:26 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/25 17:45:28 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dest_end;
	size_t	i;

	i = 0;
	dest_end = s1;
	while (*dest_end != '\0')
		dest_end++;
	while (*s2 != '\0' && i++ < n)
		*dest_end++ = *s2++;
	*dest_end = '\0';
	return (s1);
}
