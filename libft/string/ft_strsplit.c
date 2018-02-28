/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:50:07 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 15:50:08 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**clean_words(char **words, int num_words)
{
	while (num_words)
		free(words[num_words--]);
	free(words);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*word;
	int		words_idx;
	int		word_len;
	int		idx;

	if (!s || !(words = (char**)malloc(sizeof(char*) * \
										(count_words(s, c) + 1))))
		return (NULL);
	idx = 0;
	words_idx = 0;
	while (s[idx] != '\0')
		if (s[idx] == c)
			idx++;
		else
		{
			word_len = count_word_len(s + idx, c);
			if (!(word = ft_strsub(s, idx, word_len)))
				return (clean_words(words, words_idx - 1));
			words[words_idx++] = word;
			idx += word_len;
		}
	words[words_idx] = NULL;
	return (words);
}
