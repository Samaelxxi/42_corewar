/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startswith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:12:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/18 06:12:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	starts_with(char *str, char *start)
{
	if (start && str)
	{
		while (*start && *str)
			if (*start++ != *str++)
				return (0);
		if (*start == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
