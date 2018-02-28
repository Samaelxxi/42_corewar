/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:52:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/28 15:52:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_arr(char **arr)
{
	int idx;

	if (arr)
	{
		idx = 0;
		while (arr[idx])
		{
			free(arr[idx]);
			idx++;
		}
	}
	free(arr);
}
