/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:49:24 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:49:25 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n-- > 0)
	{
		if (*s1 != '\0' && *s2 != '\0')
		{
			if (*s1 != *s2)
				return (0);
		}
		else if (*s1 != *s2)
			return (0);
		else
			return (1);
		s1++;
		s2++;
	}
	return (1);
}
