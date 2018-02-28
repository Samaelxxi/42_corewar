/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:45:57 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:45:58 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	int		needle_len;

	if (needle[0] == '\0')
		return ((char*)haystack);
	cnt = 0;
	needle_len = ft_strlen(needle);
	while (haystack[cnt] != '\0' && cnt + needle_len - 1 < len)
	{
		if (ft_strnequ(haystack + cnt, needle, needle_len))
			return ((char*)(haystack + cnt));
		cnt++;
	}
	return (NULL);
}
