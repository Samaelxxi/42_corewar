/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_deleters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:37:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/01/06 03:37:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		content_deleter(void *content, size_t size)
{
	if (content && size)
		free(content);
}

void		dummy_deleter(void *content, size_t size)
{
	if (content && size)
		;
}

void		double_deleter(void *ptr, size_t size)
{
	if (ptr && size)
	{
		free(*((void **) ptr));
		free(ptr);
	}
}
