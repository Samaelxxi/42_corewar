/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:47:54 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:47:55 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memptr;
	char	*ptrcpy;

	if (!(memptr = malloc(size)))
		return (NULL);
	ptrcpy = (char*)memptr;
	while (size--)
		*ptrcpy++ = 0;
	return (memptr);
}
