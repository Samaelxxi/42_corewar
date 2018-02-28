/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:25:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/29 19:25:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*path_base(char *fullpath)
{
	int idx;

	idx = 0;
	while (fullpath[idx] != '\0')
		idx++;
	idx--;
	while (idx >= 0 && fullpath[idx] != '/')
		idx--;
	return (fullpath + idx + 1);
}
