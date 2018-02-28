/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:40:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/28 15:40:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(const char *str, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			if (!in_word)
			{
				words += 1;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (words);
}
