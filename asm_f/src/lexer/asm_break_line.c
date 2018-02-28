/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_break_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:01:33 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/15 20:01:39 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	tokenize_file(t_file_of_tokens *head, int nbr_line, int fd)
{
	char		*line;
	unsigned	i;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		nbr_line++;
		ignore_space_at_start(line, &i);
		view_and_break_line(head, line, nbr_line);
		if (line[i] && line[i] != COMMENT_CHAR)
			ft_lst_reverse(&(lst_get_line_token(head->lines)->tokens));
		else
			free(line);
	}
	ft_lst_reverse(&head->lines);
}

void	view_and_break_line(t_file_of_tokens *head, char *line, int nbr_line)
{
	unsigned int	i;

	i = 0;
	ignore_space_at_start(line, &i);
	if (line[i] == COMMENT_CHAR)
		return ;
	if (line[i] != '\0')
		create_line_lexem(head, nbr_line, line);
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		ignore_space_at_start(line, &i);
		if (line[i])
			extract_one_token(lst_get_line_token(head->lines), line, &i);
	}
}

void	ignore_space_at_start(char *line, unsigned int *position)
{
	while (line[*position] && ft_isspace(line[*position]))
		(*position)++;
}

void	create_line_lexem(t_file_of_tokens *head, int nbr_line, char *line)
{
	t_line_of_tokens *new_line_lexem;

	new_line_lexem = ft_memalloc(sizeof(t_line_of_tokens));
	new_line_lexem->line_number = nbr_line;
	new_line_lexem->origin_line = line;
	new_line_lexem->tokens = NULL;
	lst_add_line_token(&(head->lines), new_line_lexem);
}
