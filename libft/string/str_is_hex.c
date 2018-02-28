/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:09:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/01/30 14:09:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_str_hex(char *flag_arg)
{
	while (*flag_arg)
	{
		if (!ft_ishex(*flag_arg))
			return (0);
		flag_arg++;
	}
	return (1);
}
