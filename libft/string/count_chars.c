/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:04:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/18 13:04:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				count_chars(const char *str, char x)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == x)
				count++;
			i++;
		}
	return (count);
}
