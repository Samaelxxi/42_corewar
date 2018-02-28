/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_in_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:46:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 13:46:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_idx(char c, const char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
