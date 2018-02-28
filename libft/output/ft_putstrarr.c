/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:13:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/28 18:13:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **words, char del)
{
	if (words)
	{
		while (*words)
		{
			ft_putstr(*words++);
			if (*(words))
				ft_putchar(del);
		}
	}
}
