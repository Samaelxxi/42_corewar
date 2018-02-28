/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len_in_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:15:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/28 11:15:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num_len_in_chars(long long num)
{
	int len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}
