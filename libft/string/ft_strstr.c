/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:25:37 by vpaladii          #+#    #+#             */
/*   Updated: 2017/09/25 11:25:39 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int cnt;
	int find_idx;
	int found;

	if (needle[0] == '\0')
		return ((char*)haystack);
	cnt = 0;
	while (haystack[cnt] != '\0')
	{
		find_idx = 0;
		found = 1;
		while (needle[find_idx] != '\0')
		{
			if (haystack[cnt + find_idx] != needle[find_idx])
			{
				found = 0;
				break ;
			}
			find_idx++;
		}
		if (found)
			return ((char*)(haystack + cnt));
		cnt++;
	}
	return (NULL);
}
