/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:50:01 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:50:02 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		start_idx;
	int		end_idx;
	int		res_idx;

	if (!s)
		return (NULL);
	start_idx = 0;
	while (is_whitespace(s[start_idx]) && s[start_idx] != '\0')
		start_idx++;
	end_idx = start_idx;
	while (s[end_idx] != '\0')
		end_idx++;
	end_idx--;
	while (is_whitespace(s[end_idx]) && end_idx > start_idx)
		end_idx--;
	end_idx++;
	if (!(res = ft_strnew(end_idx - start_idx)))
		return (NULL);
	res_idx = 0;
	while (start_idx < end_idx)
		res[res_idx++] = s[start_idx++];
	return (res);
}
