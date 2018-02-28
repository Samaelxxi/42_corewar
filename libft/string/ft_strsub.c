/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:49:34 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:49:35 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		idx;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	idx = 0;
	while (len--)
	{
		str[idx] = s[start + idx];
		idx++;
	}
	return (str);
}
