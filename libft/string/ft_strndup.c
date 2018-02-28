/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:17:45 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/27 10:17:47 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*str;
	char		*str_start;
	size_t		size;
	size_t		strlen;

	strlen = ft_strlen(s1);
	size = (n < strlen) ? n : strlen;
	if (!(str = ft_strnew(size)))
		return (NULL);
	str_start = str;
	while (*s1 != '\0' && size--)
		*str++ = *s1++;
	*str = '\0';
	return (str_start);
}
