/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:34:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/18 14:34:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strtrim_free(char *s)
{
	char	*res;

	res = ft_strtrim(s);
	ft_strdel(&s);
	return (res);
}

char		*ft_strtrim_start(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	s = ft_strdup(s);
	return (s);
}

char		*ft_strtrim_start_free(char *s)
{
	char *res;

	res = ft_strtrim_start(s);
	ft_strdel(&s);
	return (res);
}

char		*ft_strtrim_end(char *s)
{
	int		i;

	i = (int)ft_strlen(s);
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\0'))
		i--;
	s[i + 1] = '\0';
	return (ft_strdup(s));
}
