/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file_into_tokens.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		split_file_into_tokens(t_file_of_tokens *head, int fd)
{
	char		*line;
	char		*copy_line;
	int			nbr_line;

	nbr_line = 0;
	while ((!head->champ_name || !head->champ_desc) &&
						(get_next_line(fd, &line)) != 0)
	{
		nbr_line++;
		copy_line = ft_strtrim_start_free(line);
		if (copy_line[0] == '#' || copy_line[0] == '\0')
			free(copy_line);
		else if (copy_line[0] == '.')
			check_name_or_comment(head, copy_line, &nbr_line, fd);
		else
			str_error("No name or comment");
	}
	if (!head->champ_name || !head->champ_desc)
		str_error("No name or comment");
	tokenize_file(head, nbr_line, fd);
}

void		check_name_or_comment(t_file_of_tokens *head,
						char *line, int *nbr_line, int fd)
{
	if (starts_with(line, COMMENT_CMD_STRING) && !head->champ_desc)
	{
		save_comment_or_name(&head->champ_desc, line, nbr_line, fd);
		if (ft_strlen(head->champ_desc) > COMMENT_LENGTH)
			str_error("Champion comment too long (Max length 2048)");
	}
	else if (starts_with(line, NAME_CMD_STRING) && !head->champ_name)
	{
		save_comment_or_name(&head->champ_name, line, nbr_line, fd);
		if (ft_strlen(head->champ_name) > PROG_NAME_LENGTH)
			str_error("Champion name too long (Max length 128)");
	}
	else if (head->champ_desc || head->champ_name)
		lex_error(*nbr_line,
				"You can use only one \".name\" and one \".comment\"");
	else
		lex_error(*nbr_line, "You can use only \".name\" or \".comment\"");
}
