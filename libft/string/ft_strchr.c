/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:45:25 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:45:26 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char*)s;
	while (*s_cpy != '\0' && *s_cpy != c)
		s_cpy++;
	if (*s_cpy != c)
		return (NULL);
	else
		return (s_cpy);
}
