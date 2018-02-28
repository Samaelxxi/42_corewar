/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:49:47 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:49:48 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		idx;
	int		idx2;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char*)ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		res[idx] = s1[idx];
		idx++;
	}
	idx2 = 0;
	while (s2[idx2] != '\0')
		res[idx++] = s2[idx2++];
	return (res);
}
