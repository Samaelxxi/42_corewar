/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:16:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/29 16:16:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_str(char **str1, char **str2)
{
	char *temp_ptr;

	temp_ptr = *str1;
	*str1 = *str2;
	*str2 = temp_ptr;
}

void		sort_str_arr(char **arr, int (*cmp)(const char *, const char*))
{
	int is_sorted;
	int idx;
	int size;

	is_sorted = 0;
	size = str_arr_len(arr);
	while (!is_sorted)
	{
		is_sorted = 1;
		idx = 0;
		while (idx < size - 1)
		{
			if (cmp(arr[idx], arr[idx + 1]) > 0)
			{
				ft_swap_str(&(arr[idx]), &(arr[idx + 1]));
				is_sorted = 0;
			}
			idx++;
		}
	}
}
